/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:08:50 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/16 19:29:42 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	**get_path_arr(t_list *env_list)
{
	char	*full_path;
	char	**path_arr;

	full_path = get_env_value(env_list, "PATH");
	if (full_path == NULL)
		return (NULL);
	path_arr = ft_split(full_path + 5, ":");
	free(full_path);
	if (!path_arr)
		return (NULL);
	return (path_arr);
}

char	*find_path_in_envp(char *cmd, char **path_arr)
{
	char	*tmp;
	int		i;

	i = -1;
	while (path_arr[++i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (tmp == NULL)
		{
			split_free(path_arr);
			return (NULL);
		}
		if (access(tmp, X_OK) == 0)
		{
			split_free(path_arr);
			return (tmp);
		}
		else
			free(tmp);
	}
	split_free(path_arr);
	return (NULL);
}

char	*get_absolute_path(char *cmd)
{
	char	*current_path;
	char	*cmd_path;

	current_path = getcwd(NULL, 0);
	if (current_path == NULL)
		return (NULL);
	cmd = ft_substr(cmd, 2, ft_strlen(cmd) - 2);
	if (cmd == NULL)
	{
		free(current_path);
		return (NULL);
	}
	cmd_path = ft_strjoin(current_path, "/");
	cmd_path = ft_strjoin(cmd_path, cmd);
	free(current_path);
	free(cmd);
	if (cmd_path == NULL)
		return (NULL);
	return (cmd_path);
}

char	*get_cmd_path(char *cmd, t_list *env_list)
{
	char	*cmd_path;
	char	*current_path;
	char	**path_arr;

	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd_path = ft_strdup(cmd);
	else if (ft_strncmp(cmd, "./", 2) == 0)
		cmd_path = get_absolute_path(cmd);
	else
	{
		path_arr = get_path_arr(env_list);
		if (path_arr == NULL)
			return (NULL);
		cmd_path = find_path_in_envp(cmd, path_arr);
	}
	return (cmd_path);
}

void	set_cmd_path(t_cmd_list *list, t_list *env_list)
{
	t_cmd_list *current;
	
	current = list;
	while (current)
	{
		if (current->type == T_CMD)
		{
			if (current->path)
				free(current->path);
			current->path = get_cmd_path(current->argv[0], env_list);
		}
		current = current->next;
	}
} 	