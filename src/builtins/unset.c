/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:32:07 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/18 17:25:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_builtin_argv(char	*str)
{
	if (str[0] == '-' || (str[0] >= 'a' && str[0] <= 'z') \
		|| (str[0] >= 'A' && str[0] <= 'Z'))
		return (1);
	return (0);
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

void	unset(t_ASTNode *tree, t_list **env_list)
{
	int		i;

	i = 0;
	while (tree->cmd->argv[i] != NULL)
	{
		if (!check_builtin_argv(tree->cmd->argv[i]))
		{
			write(2, "tontoshell: unset: ", 19);
			write(2, tree->cmd->argv[0], ft_strlen(tree->cmd->argv[0]));
			ft_putendl_fd(": not a valid identifier", 2);
			i++;
			continue ;
		}
		remove_env_var(env_list, tree->cmd->argv[i]);
		i++;
	}
}
