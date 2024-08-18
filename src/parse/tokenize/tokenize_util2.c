/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:16 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/18 17:00:55 by wonyocho         ###   ########.fr       */
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
