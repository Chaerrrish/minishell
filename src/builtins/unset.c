/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:32:07 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/14 15:28:29 by chaerin          ###   ########.fr       */
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

void    unset(t_ASTNode *tree, t_list **env_list)
{
	int		i;

	i = 0;
	while (tree->cmd->argv[i] != NULL)
	{
		remove_env_var(env_list, tree->cmd->argv[i]);
		i++;
	}
}
