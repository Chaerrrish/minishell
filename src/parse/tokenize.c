/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:42:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/09 15:00:40 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static int	is_whitespace(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

static void	init_tmp(t_token_set *token_iter)
{
	token_iter->set = NULL;
	token_iter->start = 0;
	token_iter->end = 0;
	token_iter->in_single_quote = 0;
	token_iter->in_double_quote = 0;
}

int	tokenize(t_shell *minishell, t_token *token_lst, char *input)
{
	t_token_set tmp;

	init_tmp(&tmp);
	tmp.set = ft_split(input, ' ');
	if (tmp.set == NULL)
		return (0);
}