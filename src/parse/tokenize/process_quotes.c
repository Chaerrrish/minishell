/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:02 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/21 14:48:24 by wonyocho         ###   ########.fr       */
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

void	process_quotes(char *input, t_token_iter *iter)
{
	while (input[iter->end]
		&& (!is_whitespace(input[iter->end]) || iter->in_sq || iter->in_dq)
		&& (input[iter->end] != '|' || iter->in_sq || iter->in_dq)
		&& !is_redirection(input, iter))
	{
		if (input[iter->end] == '\'' && !iter->in_dq)
			iter->in_sq = !iter->in_sq;
		else if (input[iter->end] == '\"' && !iter->in_sq)
			iter->in_dq = !iter->in_dq;
		iter->end++;
	}
}
