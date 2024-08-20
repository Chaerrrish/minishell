/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:04:39 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/20 16:45:13 by chaoh            ###   ########.fr       */
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

char	*cd_home(t_cmd_list *list, t_list *env_list, char *current_path)
{
	current_path = get_env_value(env_list, "HOME");
	if (!(current_path))
	{
		ft_putendl_fd("tontoshell: cd: HOME not set", 2);
		return (NULL);
	}
	return (current_path);
}

char	*cd_path(t_cmd_list *list, char *current_path, char *old_path)
{
	char	*tmp;

	if (list->argv[1][0] == '/' \
		|| ft_strcmp(list->argv[1], ".") == 0 \
		|| ft_strcmp(list->argv[1], "..") == 0)
		current_path = ft_strdup(list->argv[1]);
	else
	{
		tmp = ft_strjoin(old_path, "/");
		current_path = ft_strjoin(tmp, list->argv[1]);
		free(tmp);
	}
	if (current_path && check_path(current_path, old_path) == 0)
		return (NULL);
	return (current_path);
}

void	cd(t_cmd_list *list, t_list *env_list)
{
	char	*current_path;
	char	*old_path;

	current_path = NULL;
	old_path = getcwd(NULL, 0);
	if (list->argc == 1 || ft_strcmp(list->argv[1], "~") == 0)
	{
		current_path = cd_home(list, env_list, current_path);
		if (current_path == NULL)
			return ;
	}
	else
	{
		current_path = cd_path(list, current_path, old_path);
		if (current_path == NULL)
			return ;
	}
	if (chdir(current_path) != 0)
		perror("tontoshell: cd");
	update_pwd(env_list, current_path, old_path);
	if (current_path)
		free(current_path);
}
