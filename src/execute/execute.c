/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:16:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/27 20:16:47 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	execute(t_shell	*shell, char **envp)
{
	t_cmd_list	*current;

	if (heredoc(shell->cmd_list) == 0)	
	{
		g_status_code = 258;
		exit(g_status_code);
	}
	current = shell->cmd_list;
	while (current)
	{
		if (shell->cmd_list->next == NULL && current->token_list->type == T_BULTIN)
		{
			if (execute_builtin(shell, current, envp) == 0)
			{
				g_status_code = 2;
				exit(g_status_code);
			}
		}
		else
			make_process(current, shell);
		current = current->next;
	}
	g_status_code = get_status();
	set_signal(SHELL, SHELL);
}

void	make_process(t_cmd_list *cmd, t_shell *shell)
{
	char	**new_envp;

	new_envp = list_to_array(shell->env_list);
	if (cmd->next != NULL)
	{
		if (pipe(cmd->pipe_fd) == -1)
		{
			perror("pipe");
			g_status_code = 1;
			exit(g_status_code);
		}
	}
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		g_status_code = 1;
		exit(g_status_code);
	}
	else if (cmd->pid == 0)
	{
		change_inout(cmd);
		if (cmd->token_list->type == T_BULTIN)
		{
			execute_builtin(shell, cmd, new_envp);
			g_status_code = 0;
			exit(g_status_code);
		}
		if (cmd->token_list->type == T_WORD)
		{
			set_signal(DEFAULT, DEFAULT);
			execute_child(cmd, shell, new_envp);
			g_status_code = 0;
			split_free(new_envp);
			exit(g_status_code);
		}
	}
	else
	{
		set_signal(IGNORE, IGNORE);
		if (cmd->pipe_fd[1] != -1)
			close(cmd->pipe_fd[1]);
		execute_parent(cmd);
	}
	split_free(new_envp);
}

void	execute_parent(t_cmd_list *cmd)
{
	if (cmd->in_fd != -1 && cmd->in_fd != STDIN_FILENO)
	{
		close(cmd->in_fd);
		cmd->in_fd = -1;
	}
	if (cmd->next != NULL)
	{
		dup2(cmd->pipe_fd[0], STDIN_FILENO);
		close(cmd->pipe_fd[0]);
		close(cmd->pipe_fd[1]);
	}
	if (cmd->heredoc_file)
	{
		waitpid(cmd->pid, NULL, 0);
		unlink(cmd->heredoc_file);
		free(cmd->heredoc_file);
		cmd->heredoc_file = NULL;
	}
}

void	execute_child(t_cmd_list *cmd, t_shell *shell, char **envp)
{
	if (cmd->token_list->type == T_WORD)
	{
		set_cmd_path(cmd, shell->env_list);
		if (cmd->path == NULL)
		{
			print_cmd_error(cmd->argv[0]);
			g_status_code = 127;
			exit(g_status_code);
		}
		if (execve(cmd->path, cmd->argv, envp) < 0)
		{
			perror("execve");
			g_status_code = 1;
			exit(g_status_code);
		}
	}
	exit(0);
}
