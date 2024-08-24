/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:34:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 21:17:42 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	set_status_code(int status)
{
	g_status_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			g_status_code = 130;
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			g_status_code = 131;
		}
		else
			g_status_code = 128 + status;
	}
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
			g_status_code = 1;
			exit(1);
		}
		dup2(heredoc_fd, STDIN_FILENO);
		close(heredoc_fd);
	}
	set_redir_inout(cmd);
	if (cmd->next != NULL)
	{
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
		close(cmd->pipe_fd[1]);
		close(cmd->pipe_fd[0]);
	}
}
