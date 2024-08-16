/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:42:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:16:41 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static void	init_iter(t_token_iter *token_iter);

int	tokenize(t_shell *minishell, t_token **token_lst, char *input)
{
	t_token_iter	iter;

	init_iter(&iter);
	while (input[iter.end])
	{
		skip_whitespace(input, &iter); // 공백 스킵
		iter.start = iter.end;
		if (input[iter.end] == '|') // 문자가 파이프라면 스킵
			iter.end++;
		else
		{
			while (input[iter.end] && (!is_whitespace(input[iter.end])
				|| iter.in_squote || iter.in_dquote) && (input[iter.end] != '|'
				|| iter.in_squote || iter.in_dquote))
				{
					if (process_quotes(input[iter.end], &iter) != 0) // 얘가 0이 아닐 수가 잇냐?
						break;
					iter.end++;
				}
		}
		process_token(minishell, token_lst, input, &iter);
	}
	remove_quotes(*token_lst);
	return (iter.in_squote || iter.in_dquote); // 짝이 맞으면 0, 안맞으면 1을 리턴. 만약 1이다? -> 에러처리
}

static void	init_iter(t_token_iter *token_iter)
{
	token_iter->start = 0;
	token_iter->end = 0;
	token_iter->in_squote = 0;
	token_iter->in_dquote = 0;
}
