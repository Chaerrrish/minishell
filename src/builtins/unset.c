/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:32:07 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/28 14:11:04 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
			free_env(env);
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
		if (!check_unset_argv(list->argv[i]))
		{
			write(2, "tontoshell: unset: `", 20);
			write(2, list->argv[i], ft_strlen(list->argv[i]));
			ft_putendl_fd("': not a valid identifier", 2);
			g_status_code = 1;
			i++;
			continue ;
		}
		remove_env_var(env_list, list->argv[i]);
		i++;
	}
	g_status_code = 0;
}
