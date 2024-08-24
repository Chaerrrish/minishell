/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:07:46 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/24 19:41:31 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token	*detach_redirection(t_token *token_list)
{
	t_token	*result;
	int		i;

	i = 0;
	result = token_list;
	while (result)
	{
		i = 0;
		while (result->str[i])
			i++;
		if (is_back_redir(result, i - 1))
		{
			if (strlen(result->str) == 2
				&& (ft_strcmp(result->str, ">>") != 0
					&& ft_strcmp(result->str, "<<") != 0))
				detach(result, 1);
			if (ft_strlen(result->str) != 2 && ft_strlen(result->str) != 1)
				detach(result, i - 1);
		}
		result = result->next;
	}
	return (token_list);
}

int	is_back_redir(t_token *result, int end)
{
	if (result->str[0] != '<' || result->str[0] != '>')
	{
		if (result->str[end] == '<' || result->str[end] == '>')
			return (1);
	}
	return (0);
}

void	detach(t_token *result, int end)
{
	int		i;
	t_token	*add;

	i = 0;
	while (result->str[i] != '<' && result->str[i] != '>')
		i++;
	add = ft_calloc(1, sizeof(t_token));
	add->str = ft_strdup(ft_substr(result->str, i, end));
	add->type = get_token_type(add->str);
	result->str = ft_substr(result->str, 0, i);
	result->type = T_WORD;
	add->next = result->next;
	result->next = add;
}
