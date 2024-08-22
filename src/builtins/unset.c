/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:32:07 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/22 16:23:10 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_builtin_argv(char	*str)
{
	int	i;

	i = 1;
	if (!(str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') \
		|| (str[0] >= 'A' && str[0] <= 'Z')))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z' \
		|| str[i] >= 'A' && str[i] <= 'Z' \
		|| str[i] >= '0' && str[i] <='9' \
		|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	remove_env_var(t_list **env_list, char *key)
{
	t_list	*current;
	t_list	*previous;
	t_env	*env;

	current = *env_list;
	previous = NULL;
	while (current)
	{
		env = (t_env *)current->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			if (previous == NULL)
				*env_list = current->next;
			else
				previous->next = current->next;
			free(env->key);
			free(env->value);
			free(env);
			free(current);
			break ;
		}
		previous = current;
		current = current->next;
	}
}

void	unset(t_cmd_list *list, t_list **env_list)
{
	int		i;

	i = 1;
	while (list->argv[i] != NULL)
	{
		if (!check_builtin_argv(list->argv[i]))
		{
			write(2, "tontoshell: unset: ", 19);
			write(2, list->argv[i], ft_strlen(list->argv[i]));
			ft_putendl_fd(": not a valid identifier", 2);
			i++;
			continue ;
		}
		remove_env_var(env_list, list->argv[i]);
		i++;
	}
}
