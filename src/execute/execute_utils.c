/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:34:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/26 22:11:17 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	set_status_code(int status)
{
	int	signal_number;

	if (WIFEXITED(status))
	{
		g_status_code = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		signal_number = WTERMSIG(status);
		if (signal_number == SIGINT)
		{
			g_status_code = 130;
			printf("^C\n");
		}
		else if (signal_number == SIGQUIT)
		{
			g_status_code = 131;
			printf("^\\Quit: 3\n");
		}
		else
			g_status_code = 128 + status;
	}
}

int	get_status(void)
{
	int	i;
	int	status;

	i = 0;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_status_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGQUIT && i++ == 0)
			{
				g_status_code = 131;
				printf("^\\Quit: 3\n");
			}
			else if (WTERMSIG(status) == 2 && i++ == 0)
			{
				g_status_code = 130;
				printf("^C\n");
			}
		}
	}
	return (g_status_code);
}


void	change_inout(t_cmd_list *cmd)
{
	int	heredoc_fd;

	if (cmd->heredoc_file)
	{
		heredoc_fd = open(cmd->heredoc_file, O_RDONLY);
		if (heredoc_fd == -1)
		{
			perror("open heredoc file");
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
