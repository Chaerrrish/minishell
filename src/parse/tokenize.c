/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:42:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:41:38 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static void	init_iter(t_token_iter *token_iter)
{
	token_iter->start = 0;
	token_iter->end = 0;
	token_iter->in_squote = 0;
	token_iter->in_dquote = 0;
}

int	tokenize(t_shell *minishell, t_token *token_lst, char *input)
{
	t_token_iter	iter;

	init_iter(&iter);
	while (input[iter.end])
	{
		skip_whitespace(input, &iter);
		iter.start = iter.end;
		if (input[iter.end] == '|') // 현재 문자가 파이프라면
			iter.end++;
		else
		{
			while (input[iter.end] && (!is_whitespace(input[iter.end])
				|| iter.in_squote || iter.in_dquote) && (input[iter.end] != '|'
				|| iter.in_squote || iter.in_dquote))
				{
					if (process_quotes(input[iter.end], &iter) != 0)
						break;
					iter.end++;
				}
		}
		process_token(minishell, token_lst, input, &iter);
	}
	tokenize_remove_quotes(*token_lst);
	return (iter.in_squote || iter.in_dquote);
}
