/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tonto_is_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:29:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 15:18:29 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	tonto_is_free(t_shell *minishell)
{
	free_env_list(minishell->env_list);
	free_cmd_list(minishell->cmd_list);
}

void	free_env_list(t_list *lst)
{
	t_list	*tmp;
	t_env	*env;

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
	t_token		*token;
	int		i;
	
	while (cmd_list)
	{
		tmp = cmd_list;
		free_token_list(cmd_list->token_list);
		if (cmd_list->argc) // argc가 0이 아니면 argv가 있는거겟죠?
		{
			i = 0;
			while (cmd_list->argv[i])
			{
				free(cmd_list->argv[i]);
				i++;
			}
		}
		if (cmd_list->path)
			free(cmd_list->path);
		cmd_list = cmd_list->next;
		free(tmp);
	}
}

void	free_token_list(t_token *token_list)
{
	t_token *temp;

	while (token_list)
	{
		temp = token_list;
		if (token_list->str)
			free(token_list->str);
		token_list = token_list->next;
		free(temp);
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