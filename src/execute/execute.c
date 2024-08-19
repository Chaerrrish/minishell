/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:16:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/19 19:41:26 by chaoh            ###   ########.fr       */
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
			execute_cmd(current, shell->env_list);
		current = current->next;
	}
}

void	execute_cmd(t_cmd_list *cmd, t_shell *shell)
{
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
			execute_child(cmd, shell->env_list);
	}
	else
	{
		waitpid(cmd->pid, NULL, 0);
	}
}

void	execute_child(t_cmd_list *cmd, t_list *env_list)
{
	if (cmd->token_list->type == T_WORD)
	{
		set_cmd_path(cmd, env_list);
		if (execve(cmd->path, cmd->argv[0], env_list) < 0)
			return ;
	}
}
