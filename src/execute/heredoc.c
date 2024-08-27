#include "../header/minishell.h"

int	heredoc(t_cmd_list *list)
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
				if (check_heredoc(current, token) == 0)
					return (0);
			}	
			token = token->next;
		}
		current = current->next;
	}
	set_signal(SHELL, SHELL);
	return (1);
}

int	check_heredoc(t_cmd_list *list, t_token *token)
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
	execute_heredoc(delimeter, list);
	free(delimeter);
	return (1);
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

void	execute_heredoc(char *delimeter, t_cmd_list *cmd)
{
	int		fd;
	char	*filename;

	set_signal(HEREDOC, IGNORE);
	filename = make_tmp_file();
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open");
		free(filename);
		return ;
	}
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
	if (cmd->heredoc_file)
		free(cmd->heredoc_file);
	cmd->heredoc_file = filename;
	set_signal(SHELL, SHELL);
}

void	heredoc_main(int fd, char *delimeter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			break ;
		}
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
}