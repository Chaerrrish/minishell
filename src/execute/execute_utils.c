/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:34:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/29 18:24:09 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
			else if (WTERMSIG(status) == SIGINT && i++ == 0)
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
	set_pipe_inout(cmd);
}

void	set_pipe_inout(t_cmd_list *cmd)
{
	if (cmd->next != NULL)
	{
		if (dup2(cmd->pipe_fd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 pipe fd");
			g_status_code = 1;
			exit(g_status_code);
		}
		close(cmd->pipe_fd[1]);
	}
}

void	unlink_heredoc_files(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->heredoc_cnt)
	{
		if (shell->heredoc_files[i])
		{
			unlink(shell->heredoc_files[i]);
			free(shell->heredoc_files[i]);
			shell->heredoc_files[i] = NULL;
		}
		i++;
	}
	shell->heredoc_cnt = 0;
}

char	*make_tmp_file(void)
{
	char	*filename;
	char	*itoa_num;
	int		i;

	i = 0;
	while (1)
	{
		itoa_num = ft_itoa(i);
		filename = ft_strjoin("/tmp/heredoc_tmp", itoa_num);
		free(itoa_num);
		if (access(filename, F_OK) != 0)
			return (filename);
		else
			free(filename);
		i++;
	}
}
