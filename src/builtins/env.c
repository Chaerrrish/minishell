/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:33:11 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/26 17:06:35 by chaoh            ###   ########.fr       */
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
		g_status_code = 127;
		return ;
	}
	while (current != NULL)
	{
		env = (t_env *)current->content;
		if (ft_strlen(env->value) != 0)
		{
			write(list->out_fd, env->key, ft_strlen(env->key));
			write(list->out_fd, "=", 1);
			write(list->out_fd, env->value, ft_strlen(env->value));
			write(list->out_fd, "\n", 1);
		}
		current = current->next;
	}
	g_status_code = 0;
}
