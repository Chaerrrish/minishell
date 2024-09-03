/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tonto_is_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:29:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 19:56:41 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	free_env_list(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		free_env(lst->content);
		lst = lst->next;
		free(tmp);
	}
}

void	free_cmd_list(t_cmd_list *cmd_list)
{
	t_cmd_list	*tmp;
	int			i;

	while (cmd_list)
	{
		tmp = cmd_list->next;
		free_token_list(cmd_list->token_list);
		if (cmd_list->argv)
		{
			i = 0;
			while (cmd_list->argv[i])
			{
				free(cmd_list->argv[i]);
				i++;
			}
			free(cmd_list->argv);
		}
		if (cmd_list->path)
			free(cmd_list->path);
		free(cmd_list);
		cmd_list = tmp;
	}
}

void	free_token_list(t_token *token_list)
{
	t_token	*temp;

	while (token_list)
	{
		temp = token_list->next;
		if (token_list->str)
			free(token_list->str);
		free(token_list);
		token_list = temp;
	}
}

void	free_env(void *content)
{
	t_env	*env;

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
