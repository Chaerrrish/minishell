/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:16 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/20 17:49:43 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_type(char c)
{
	if (c == '\'')
		return (T_SINGLE_QUOTE);
	else
		return (T_DOUBLE_QUOTE);
}

int	is_quotation_str(char *str, int start, int end)
{
	if (str[start] == '\'' && str[end - 1] == '\'')
		return (1);
	if (str[start] == '\"' && str[end - 1] == '\"')
		return (1);
	return (0);
}

t_token	*token_lst_last(t_token *token_lst)
{
	if (token_lst == NULL)
		return (NULL);
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	return (token_lst);
}

