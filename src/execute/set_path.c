/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:33:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/25 19:11:50 by chaoh            ###   ########.fr       */
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
	path_arr = ft_split(full_path + 5, ':');
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
	t_cmd_list	*current;
	t_token		*token;

	current = list;
	if (ft_strlen(current->argv[0]) == 0)
		return ;
	while (current)
	{
		token = current->token_list;
		while (token)
		{
			if (current->token_list->type != T_BULTIN)
			{
				if (current->path)
					free(current->path);
				current->path = get_cmd_path(current->argv[0], env_list);
			}
			token = token->next;
		}
		current = current->next;
	}
}
