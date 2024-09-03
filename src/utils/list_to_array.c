/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:39:21 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 19:52:43 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_list(t_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

char	**list_to_array(t_list *list)
{
	int		count;
	char	**result;
	int		i;
	t_env	*env;

	count = count_list(list);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (list)
	{
		env = (t_env *)list->content;
		result[i] = ft_strdup(env->data);
		if (!result[i])
			memory_error();
		list = list->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}
