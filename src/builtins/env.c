/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:33:11 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/18 14:50:03 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	env(t_cmd_list *list, t_list *env_list)
{
	t_env	*env;
	t_list	*current;

	current = env_list;
	if (list->argc > 1)
	{
		write(2, "env: ", 5);
		write(2, list->argv[1], ft_strlen(list->argv[1]));
		ft_putendl_fd(": No such file or directory", 2);
		return ;
	}
	while (current != NULL)
	{
		env = (t_env *)current->content;
		if (ft_strlen(env->value) != 0)
			printf("%s=%s\n", env->key, env->value);
		current = current->next;
	}
}

