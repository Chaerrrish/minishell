/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:13:40 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/14 15:50:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_free(t_token *token)
{
	if (token->str)
		free(token->str);
	free(token);
}

void	token_lst_free(t_token **token_lst)
{
	t_token	*token;
	t_token	*n_token;

	token = *token_lst;
	while (token)
	{
		n_token = token->next;
		token_free(token);
		token = n_token;
	}
	free(*token_lst);
	*token_lst = NULL;
}

// token 리스트의 마지막 요소를 반환하는 함수
t_token	*token_lst_back(t_token *token_lst)
{
	if (token_lst == NULL) // token 리스트가 비어있다면
		return (NULL); // NULL 반환
	while (token_lst->next != NULL) // 마지막 요소를 찾을 때까지
		token_lst = token_lst->next; // 다음 요소로 이동
	return (token_lst); // 마지막 요소 반환
}

t_token	*expanded_new_token(char *line, int l, int r)
{
	t_token	*token;
	char	*tmp;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		memory_error();
	token->str = ft_substr(line, l, r - l);
	if (token->str == NULL)
		memory_error();
	token->type = get_token_type(token->str);
	return (token);
}
