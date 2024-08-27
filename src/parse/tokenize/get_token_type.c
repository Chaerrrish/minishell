/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:53:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/27 13:38:42 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_token_type(const char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (T_PIPE);
	else if (ft_strcmp(str, "<") == 0)
		return (T_REDIR_IN);
	else if (ft_strcmp(str, ">") == 0)
		return (T_REDIR_OUT);
	else if (ft_strcmp(str, "<<") == 0)
		return (T_REDIR_HERE);
	else if (ft_strcmp(str, ">>") == 0)
		return (T_REDIR_APPEND);
	else if (ft_strcmp(str, "2>") == 0)
		return (T_REDIR_ERR);
	else
		return (is_builtin(str));
}

int	is_builtin(const char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "echo") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "env") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "exit") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "export") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "pwd") == 0)
		return (T_BULTIN);
	else if (ft_strcmp(str, "unset") == 0)
		return (T_BULTIN);
	else
		return (T_WORD);
}
