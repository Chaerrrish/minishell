/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:15:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/18 19:35:57 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	lst_free(t_list *lst)
{
	t_list	*tmp;
	t_env	*env;

	while (lst != NULL)
	{
		tmp = lst;
		env = (t_env *)lst->content; // content를 변환해줘서 free해줄것임미다
		if (env)
		{
			free(env->data);
			free(env->key);
			free(env->value);
			free(env);
		}
		lst = lst->next;
		free(tmp);
	}
}

void	free_env(void *content)
{
	t_env *env;

	env = (t_env *)content;
	if (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		if (env->data)
			free(env->data);
		free(env);
	}
}
