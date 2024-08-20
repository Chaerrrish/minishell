/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:16:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/19 21:34:09 by chaoh            ###   ########.fr       */
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
		cmd->pid = fork();
	if (cmd->pid == -1)
		return ;
	else if (cmd->pid == 0)
	{
		if (cmd->token_list->type == T_BULTIN)
		{
			execute_builtin(shell);
			exit(0);
		}
		else if (cmd->token_list->type == T_WORD)
		{
			execute_child(cmd, shell, envp);
			exit(0);
		}
	}
	else
	{
		waitpid(cmd->pid, NULL, 0);
	}
	split_free(envp);
}

void	execute_child(t_cmd_list *cmd, t_shell *shell, char  **envp)
{
	if (cmd->token_list->type == T_WORD)
	{
		set_cmd_path(cmd, shell->env_list);
		if (cmd->path == NULL)
			print_cmd_error(cmd->argv[0]);
		if (execve(cmd->path, cmd->argv, envp) < 0)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	exit(0);
}
