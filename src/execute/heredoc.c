/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:26:21 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/18 17:49:10 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	heredoc(t_cmd_list *list)
{
	t_cmd_list	*current;
	t_token		*token;

	current = list;
	while (current)
	{
		token = current->token_list;
		while (token)
		{
			if (token->type == T_REDIR_HERE)
				check_heredoc(current, token);
			token = token->next;
		}
		current = current->next;
	}
}

void	check_heredoc(t_cmd_list *list, t_token *token)
{
	char	*delimeter;

	if (token->next->type == T_NULL)
	{
		ft_putendl_fd("tontoshell: syntax error near \
						unexpected token 'newline'", 2);
		return ;
	}
	delimeter = ft_strdup(token->next->str);
	if (delimeter == NULL)
		return ;
	execute_heredoc(delimeter);
	free(delimeter);
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

void	execute_heredoc(char *delimeter)
{
	int	fd;
	char	*filename;

	filename = make_tmp_file();
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open");
		free(filename);
		return ;
	}
	heredoc_parent(fd, delimeter);
	close(fd);
	if (fork() == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			free(filename);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	wait(NULL);
	unlink(filename);
	 
	free(filename);
}

void	heredoc_parent(int fd, char *delimeter)
{
	char	*line;
	while (1)
	{
		line = readline("> ");
		if (line)
		{
			if (ft_strcmp(line, delimeter) != 0)
			{
				write(fd, line, ft_strlen(line));
				write(fd, "\n", 1);
				free(line);
			}
			else
				return ;
		}
		free(line);
	}
}


