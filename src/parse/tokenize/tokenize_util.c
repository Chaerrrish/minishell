/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:16 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/03 13:56:30 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_type(char c)
{
	if (c == '\'')
		return (T_SINGLE_QUOTE);
	else
		return (T_DOUBLE_QUOTE);
}

void	skip_whitespace(const char *input, t_token_iter *iter)
{
	while (input[iter->end] && is_whitespace(input[iter->end]))
		iter->end++;
}

int	is_quote(char *str, int start, int end)
{
	if (str[start] == '\'' && str[end - 1] == '\'')
		return (1);
	if (str[start] == '\"' && str[end - 1] == '\"')
		return (1);
	return (0);
}

int	is_redirection(const char *input, t_token_iter *iter)
{
	if (input[iter->end] == '<' || input[iter->end] == '>')
	{
		iter->end++;
		if (input[iter->end] == input[iter->end - 1])
			iter->end++;
		return (1);
	}
	return (0);
}

int	is_whitespace(const char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}
