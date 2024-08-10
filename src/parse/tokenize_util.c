/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:25:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:44:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 토큰을 생성하고 리스트에 추가함
void	process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter)
{
	t_token	*token;

	if (iter->end > iter->start) // 토큰의 길이가 0보다 크다면
	{
		token = new_token(line, iter->start, iter->end); // 새로운 토큰 생성
		if (!tokenize_expend(mini, token_lst, token)) // 토큰 확장에 실패하면
			add_token(token_lst, token); // 토큰 리스트에 추가
	}
}