/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:59:33 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/21 17:48:26 by chaoh            ###   ########.fr       */
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
		// else if (token->type == T_REDIR_IN)
		// 	redir_in(cmd, token);
		token = token->next;
	}
	
}

void	redir_out(t_cmd_list *cmd, t_token *token)
{
	int	redir_fd;
	int	target_fd;

	if (token->next == NULL)
	{
		ft_putendl_fd("tontoshell: syntax error near unexpected token `newline'", 2);
		return ;
	}
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
		target_fd = cmd->out_fd;
	else
		target_fd = STDOUT_FILENO;
	dup2(redir_fd, target_fd);
	close(redir_fd);
}


