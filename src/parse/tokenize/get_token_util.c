/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:22:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/03 13:56:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token	*get_str(t_token *result, char *input, int start, int end)
{
	char	*tmp;

	result->type = check_token_type(input[start]);
	tmp = result->str;
	if (start + 1 == end)
		result->str = ft_calloc(0, sizeof(char));
	else
		result->str = ft_substr(input, start + 1, end - start - 2);
	if (!result->str)
		memory_error();
	free(tmp);
	return (result);
}

void	sum_splited_env(t_token **token_lst, char *new_line)
{
	t_token	*tmp;
	char	**splited;
	int		i;

	splited = ft_split(new_line, ' ');
	i = 0;
	while (splited[i])
	{
		tmp = expanded_new_token(splited[i], 0, ft_strlen(splited[i]));
		add_to_last_token(token_lst, tmp);
		i++;
	}
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
