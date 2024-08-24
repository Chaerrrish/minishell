/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:59:33 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 19:11:46 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	redirection(t_cmd_list *cmd)
{
	t_token	*token;

	token = cmd->token_list;
	while (token)
	{
		if (token->type == T_REDIR_OUT || token->type == T_REDIR_APPEND)
			redir_out(cmd, token);
		else if (token->type == T_REDIR_IN)
			redir_in(cmd, token);
		token = token->next;
	}
}

void	redir_out(t_cmd_list *cmd, t_token *token)
{
	int	redir_fd;

	redir_fd = -1;
	if (token->next == NULL)
	{
		ft_putendl_fd(\
				"tontoshell: syntax error near unexpected token `newline'", 2);
		return ;
	}
	while (token->next && (token->next->type == T_REDIR_OUT \
			|| token->next->type == T_REDIR_APPEND))
		token = token->next;
	if (token->type == T_REDIR_OUT)
		redir_fd = open(token->next->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (token->type == T_REDIR_APPEND)
		redir_fd = open(token->next->str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (redir_fd == -1)
	{
		perror("open");
		return ;
	}
	if (cmd->out_fd != -1)
		close(cmd->out_fd);
	cmd->out_fd = redir_fd;
}

void	redir_in(t_cmd_list *cmd, t_token *token)
{
	int		redir_fd;
	t_token	*last;

	last = get_last_redir(token);
	if (last == NULL || last->next == NULL)
	{
		write(2, \
			"tontoshell: syntax error near unexpected token `newline'", 56);
		return ;
	}
	redir_fd = open(token->next->str, O_RDONLY);
	if (redir_fd == -1)
	{
		write(2, "tontoshell: ", 12);
		write(2, token->next->str, ft_strlen(token->next->str));
		ft_putendl_fd(": No such file or directory", 2);
		return ;
	}
	if (cmd->in_fd != -1)
		close(cmd->in_fd);
	cmd->in_fd = redir_fd;
}

void	set_redir_inout(t_cmd_list *cmd)
{
	redirection(cmd);
	if (cmd->in_fd != -1)
	{
		dup2(cmd->in_fd, STDIN_FILENO);
		close(cmd->in_fd);
	}
	if (cmd->out_fd != -1)
	{
		dup2(cmd->out_fd, STDOUT_FILENO);
		close(cmd->out_fd);
	}
}

t_token	*get_last_redir(t_token *token)
{
	while (token)
	{
		if (token->type == T_REDIR_IN)
			return (token);
		token = token -> next;
	}
	return (NULL);
}
