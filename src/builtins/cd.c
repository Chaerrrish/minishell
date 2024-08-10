/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:04:39 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/10 21:30:51 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_path(t_list *env_list, char *envp)
{
	t_env	*env;
	t_list	*current;
	char	*path;

	current = env_list;
	while (current)
	{
		env = (t_env *)current->content;
		if (ft_strcmp(env->key, envp) == 0)
		{
			path = ft_strdup(env->value);
			break ;
		}
		current = current->next;
	}
	return (path);
}

void	update_pwd(t_ASTNode *tree, t_list *env_list, char *current_path, char *old_path)
{
	t_list	*current;
	t_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_env *)current->content;
		if (ft_strcmp(env->key, "PWD"))
			env->value = current_path;
		else if (ft_strcmp(env->key, "OLDPWD"))
			env->value = old_path;
		current = current->next;
	}
}

void	cd(t_ASTNode *tree, t_list *env_list)
{

}
