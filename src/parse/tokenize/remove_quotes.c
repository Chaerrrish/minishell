/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:14:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/25 20:42:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	remove_leftover_dquote(t_token *token);

void	remove_quotes(t_token *token_lst)
{
	while (token_lst)
	{
		printf("before: %s\n", token_lst->str);
		do_remove(token_lst);
		printf("do_remove: %s\n", token_lst->str);
		remove_leftover_dquote(token_lst);
		printf("leftover: %s\n", token_lst->str);
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

void	remove_leftover_dquote(t_token *token)
{
	int	i;
	int	j;
	int	len;
	int	dq_cnt;
	char	*tmp;

	i = 0;
	dq_cnt = 0;
	while (token->str[i])
	{
		if (token->str[i] == '\"')
			dq_cnt++;
		i++;
	}
	len = i - dq_cnt + 1;
	tmp = (char *)ft_calloc(i - dq_cnt + 1, sizeof(char));
	i = 0;
	j = 0;
	while (i <= len)
	{
		if (token->str[i] != '\"')
		{
			tmp[j] = token->str[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	free(token->str);
	token->str = tmp;
}
