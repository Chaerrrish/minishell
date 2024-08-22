/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:42:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/21 14:47:33 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static void	init_iter(t_token_iter *token_iter);
static void	skip_whitespace(const char *input, t_token_iter *iter);
int	is_redirection(const char *input, t_token_iter *iter);

int	tokenize(t_shell *minishell, t_token **token_lst, char *input)
{
	t_token_iter	iter;

	init_iter(&iter);
	while (input[iter.end])
	{
		skip_whitespace(input, &iter);
		iter.start = iter.end;
		if (is_redirection(input, &iter));
		else if (input[iter.end] == '|')
			iter.end++;
		else
			process_quotes(input, &iter);
		process_token(minishell, token_lst, input, &iter);
	}
	remove_quotes(*token_lst);
	return (iter.in_sq || iter.in_dq);
}

static void	init_iter(t_token_iter *token_iter)
{
	token_iter->start = 0;
	token_iter->end = 0;
	token_iter->in_sq = 0;
	token_iter->in_dq = 0;
}

static void	skip_whitespace(const char *input, t_token_iter *iter)
{
	while (input[iter->end] && is_whitespace(input[iter->end]))
		iter->end++;
}

int	is_redirection(const char *input, t_token_iter *iter)
{
	if (input[iter->end] == '<' || input[iter->end] == '>')
	{
		iter->end++;
		if (input[iter->end] == input[iter->end - 1]) // << 또는 >> 처리
			iter->end++;
		return 1; // 리다이렉션이 발견됨
	}
	return 0; // 리다이렉션이 아님
}
