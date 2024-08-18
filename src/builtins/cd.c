/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:04:39 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/18 18:57:05 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
			env->value = ft_strdup(current_path);
		}
		else if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(old_path);
		}
		current = current->next;
	}
}

int	check_path(char *path, char *old_path)
{
	if (access(path, F_OK) != 0)
	{
		write(2, "tontoshell: cd: ", 16);
		write(2, path, ft_strlen(path));
		ft_putendl_fd(": No such file or directory", 2);
		free(old_path);
		free(path);
		return (0);
	}
	return (1);
}

void	cd(t_cmd_list *list, t_list *env_list)
{
	char	*current_path;
	char	*old_path;
	char	*tmp;

	old_path = getcwd(NULL, 0);
	if (list->argc == 1) // 인자가 없을 때 HOME으로 이동
		current_path = get_env_value(env_list, "HOME");
	else
	{
		if (ft_strcmp(list->argv[1], ".") == 0 \
			|| ft_strcmp(list->argv[1], "..") == 0)
			current_path = ft_strdup(list->argv[1]);
		else
		{
			tmp = ft_strjoin(old_path, "/");
			current_path = ft_strjoin(tmp, list->argv[1]);
			free(tmp);
		}
		if (check_path(current_path, old_path) == 0)
			return ;
	}
	update_pwd(env_list, current_path, old_path);
	chdir(current_path);
	free(old_path);
	free(current_path);
}
