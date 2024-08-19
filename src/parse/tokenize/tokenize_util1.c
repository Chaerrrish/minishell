/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:13:40 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 14:26:12 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_free(t_token *token)
{
	if (token->str)
		free(token->str);
	free(token);
}

void	token_lst_free(t_token *token_lst)
{
	t_token	*tmp;

	while (token_lst)
	{
		tmp = token_lst->next;
		if (token_lst->str)
			free(token_lst->str);
		free(token_lst);
		token_lst = tmp;
	}
}

// token 리스트의 마지막 요소를 반환하는 함수
t_token	*token_lst_last(t_token *token_lst)
{
	if (token_lst == NULL) // token 리스트가 비어있다면
		return (NULL); // NULL 반환
	while (token_lst->next != NULL) // 마지막 요소를 찾을 때까지
		token_lst = token_lst->next; // 다음 요소로 이동
	return (token_lst); // 마지막 요소 반환
}
