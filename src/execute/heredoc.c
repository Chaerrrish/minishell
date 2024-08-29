/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:26:21 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/29 18:22:42 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	heredoc(t_cmd_list *list, t_shell *shell)
{
	t_cmd_list	*current;
	t_token		*token;

	set_signal(HEREDOC, DEFAULT);
	current = list;
	while (current)
	{
		token = current->token_list;
		while (token)
		{
			if (token->type == T_REDIR_HERE)
			{
				if (check_heredoc(current, token, shell) == 0)
					return (0);
			}	
			token = token->next;
		}
		current = current->next;
	}
	set_signal(SHELL, SHELL);
	return (1);
}

int	check_heredoc(t_cmd_list *list, t_token *token, t_shell *shell)
{
	char	*delimeter;
	char	*err_str;

	err_str = "tontoshell: syntax error near unexpected token 'newline'";
	if (token->next == NULL)
	{
		ft_putendl_fd(err_str, 2);
		g_status_code = 258;
		return (0);
	}
	delimeter = ft_strdup(token->next->str);
	if (delimeter == NULL)
		return (0);
	execute_heredoc(delimeter, list, shell);
	free(delimeter);
	return (1);
}

int	create_heredoc_file(t_shell *shell, char **filename)
{
	int	fd;

	*filename = make_tmp_file();
	if (shell->heredoc_cnt < 100)
	{
		shell->heredoc_files[shell->heredoc_cnt] = *filename;
		shell->heredoc_cnt++;
	}
	fd = open(*filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open");
		free(*filename);
		return (-1);
	}
	return (fd);
}

void	execute_heredoc(char *delimeter, t_cmd_list *cmd, t_shell *shell)
{
	int		fd;
	char	*filename;

	fd = create_heredoc_file(shell, &filename);
	if (fd == -1)
		return ;
	heredoc_main(fd, delimeter);
	close(fd);
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	cmd->in_fd = open(filename, O_RDONLY);
	if (cmd->in_fd == -1)
	{
		perror("open");
		free(filename);
		return ;
	}	
	cmd->heredoc_file = filename;
}

void	heredoc_main(int fd, char *delimeter)
{
	char	*line;

	set_signal(HEREDOC, IGNORE);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (get_status() == 130)
		{
			free(line);
			break ;
		}
		if (ft_strcmp(line, delimeter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	set_signal(SHELL, SHELL);
}
