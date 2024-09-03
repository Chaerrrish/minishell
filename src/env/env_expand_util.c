/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:20 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 20:56:39 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_env	*find_by_key(t_list *env_list, char *target)
{
	t_list	*list;

	list = env_list;
	while (list)
	{
		if (ft_strcmp(((t_env *)list->content)->key, target) == 0)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

int	is_valid(char *s, int i)
{
	if (s[i] == '$')
	{
		if (s[i + 1] == '\0')
			return (1);
		if (s[i + 1] && s[i + 1] == '$')
			return (1);
		if (s[i + 1] && s[i + 1] == '_')
			return (1);
		if (s[i + 1] && s[i + 1] == '?')
			return (1);
		if (s[i + 1] && (s[i + 1] >= 'A' || s[i + 1] <= 'Z'))
			return (1);
		if (s[i + 1] && (s[i + 1] >= 'a' || s[i + 1] <= 'z'))
			return (1);
	}
	return (0);
}

int	find_start_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_valid(s, i))
			return (i);
		i++;
	}
	return (-1);
}

int	find_end_pos(char *s, int i)
{
	if (s[i] == '$')
		return (i - 1);
	if (s[i] == '?')
		return (i + 1);
	while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')
		|| s[i] == '_' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i - 1);
}

char	*get_env_value(t_list *env_list, char *key)
{
	char	*result;
	t_env	*env;

	env = find_by_key(env_list, key);
	if (!env)
		result = ft_strdup("");
	else
		result = ft_strdup(env->value);
	if (!result)
		memory_error();
	return (result);
}
