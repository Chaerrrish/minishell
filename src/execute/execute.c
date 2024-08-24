/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:16:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 18:00:14 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	execute(t_shell	*shell)
{
	t_cmd_list	*current;

	heredoc(shell->cmd_list);
	current = shell->cmd_list;
	while (current)
	{
		if (current->next == NULL && current->token_list->type == T_BULTIN)
			execute_builtin(shell);
		else
			execute_cmd(current, shell);
		current = current->next;
	}
}

void	execute_cmd(t_cmd_list *cmd, t_shell *shell)
{
	char	**envp;

	envp = list_to_array(shell->env_list);
	if (cmd->next != NULL)
	{
		if (pipe(cmd->pipe_fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
	}
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (cmd->pid == 0)
	{
		change_inout(cmd);
		if (cmd->token_list->type == T_BULTIN)
		{
			execute_builtin(shell);
			exit(0);
		}
		if (cmd->token_list->type == T_WORD)
		{
			execute_child(cmd, shell, envp);
			exit(0);
		}
	}
	else
		execute_parent(cmd);
	split_free(envp);
}

void	change_inout(t_cmd_list *cmd)
{
	int	heredoc_fd;

	if (cmd->heredoc_file)
	{
		heredoc_fd = open(cmd->heredoc_file, O_RDONLY);
		if (heredoc_fd == -1)
		{
			perror("open heeredoc file");
			exit(EXIT_FAILURE);
		}
		dup2(heredoc_fd, STDIN_FILENO);
		close(heredoc_fd);
	}
	set_redir_inout(cmd);
	if (cmd->next != NULL)
	{
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
		close(cmd->pipe_fd[0]);
		close(cmd->pipe_fd[1]);
	}
}

void	execute_parent(t_cmd_list *cmd)
{
	int	status;

	if (cmd->in_fd != -1)
	{
		close(cmd->in_fd);
		cmd->in_fd = -1;
	}
	waitpid(cmd->pid, &status, WUNTRACED);
	set_status_code(status);
	if (cmd->heredoc_file)
	{
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
			exit(1);
		}
		if (execve(cmd->path, cmd->argv, envp) < 0)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	exit(0);
}
