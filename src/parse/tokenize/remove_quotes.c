/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:14:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/25 15:51:03 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	remove_quotes(t_token *token_lst)
{
	while (token_lst)
	{
		do_remove(token_lst);
		token_lst = token_lst->next;
	}
}

void	do_remove(t_token *token)
{
	int		i;
	int		j;
	int		length;
	char	*new_str;

	i = 0;
	j = 0;
	length = ft_strlen(token->str);
	new_str = (char *)ft_calloc(length + 1, sizeof(char));
	while (i < length)
	{
		if (((token->type != T_SINGLE_QUOTE && token->type != T_DOUBLE_QUOTE)
				&& (token->str[i] != '\'' || token->str[i] != '\"'))
			|| ((token->str[i] != '\'' && token->type == T_SINGLE_QUOTE)
				|| (token->str[i] != '"' && token->type == T_DOUBLE_QUOTE)))
		{
			new_str[j++] = token->str[i];
		}
		i++;
	}
	new_str[j] = '\0';
	free(token->str);
	token->str = new_str;
}
