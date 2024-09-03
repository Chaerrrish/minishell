/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:42:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/03 13:43:28 by wonyocho         ###   ########.fr       */
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
		skip_whitespace(input, &iter);
		iter.start = iter.end;
		if (is_redirection(input, &iter))
			;
		if (input[iter.end] == '|')
			iter.end++;
		else
			process_quotes(input, &iter);
		get_token(minishell, token_lst, input, &iter);
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
