/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:16 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 19:29:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(const char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

void	skip_whitespace(const char *input, t_token_iter *iter)
{
	while (input[iter->end] && is_whitespace(input[iter->end]))
		iter->end++;
}

int	is_quotation_str(char *str, int l, int r)
{
	if (str[l] == '\'' && str[r - 1] == '\'')
		return (1);
	if (str[l] == '\"' && str[r - 1] == '\"')
		return (1);
	return (0);
}

t_token	*token_lst_last(t_token *token_lst)
{
	if (token_lst == NULL) // token 리스트가 비어있다면
		return (NULL); // NULL 반환
	while (token_lst->next != NULL) // 마지막 요소를 찾을 때까지
		token_lst = token_lst->next; // 다음 요소로 이동
	return (token_lst); // 마지막 요소 반환
}
