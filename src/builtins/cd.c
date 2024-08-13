/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:04:39 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/13 17:24:09 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_path(t_list *env_list, char *envp)
{
	t_env	*env;
	t_list	*current;
	char	*path;

	path = NULL;
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

void	update_pwd(t_list *env_list, char *current_path, char *old_path)
{
	t_list	*current;
	t_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_env *)current->content;
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			free(env->value);
			env->value = current_path;
		}
		else if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = old_path;
		}
		current = current->next;
	}
}

void	cd(t_ASTNode *tree, t_list *env_list)
{
	char	*current_path;
	char	*old_path;
	char	*tmp;

	old_path = find_path(env_list, "PWD");
	if (tree->cmd->argv == NULL) // 인자가 없을 때 HOME으로 이동
		current_path = find_path(env_list, "HOME");
	else
	{
		current_path = ft_strjoin(old_path, "/");
		tmp = current_path;
		current_path = ft_strjoin(current_path, tree->cmd->argv[0]);
		free(tmp);
		if (access(current_path, F_OK) != 0)
		{
			printf("minishell: cd: %s: No such file or directory\n", current_path);
			free(old_path);
			free(current_path);
			return ;
		}
		update_pwd(env_list, current_path, old_path);
		chdir(current_path);
		free(old_path);
		free(current_path);
	}
}
