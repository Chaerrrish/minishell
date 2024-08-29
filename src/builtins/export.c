/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:27:13 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/29 18:07:16 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_update_env(t_list *env_list, char **split_input, char *input)
{
	t_env	*new_env;
	t_list	*current;

	current = env_list;
	while (current)
	{
		new_env = (t_env *)current->content;
		if (ft_strcmp(new_env->key, split_input[0]) == 0)
		{
			free(new_env->value);
			if (split_input[1] != NULL)
				new_env->value = ft_strdup(split_input[1]);
			else
				new_env->value = ft_strdup("");
			free(new_env->data);
			new_env->data = ft_strdup(input);
			split_free(split_input);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

t_env	*add_env(char **split_input)
{
	t_env	*new_env;
	char	*temp;

	temp = NULL;
	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		split_free(split_input);
		return (NULL);
	}
	new_env->key = ft_strdup(split_input[0]);
	if (split_input[1] == NULL)
	{
		new_env->value = ft_strdup("");
		new_env->data = ft_strdup(new_env->key);
	}
	else
	{
		new_env->value = ft_strdup(split_input[1]);
		temp = ft_strjoin(new_env->key, "=");
		new_env->data = ft_strjoin(temp, new_env->value);
		free(temp);
	}
	return (new_env);
}

void	export_main(t_list **env_list, char *input)
{
	t_env	*new_env;
	t_list	*new_node;
	char	**split_input;

	split_input = ft_split(input, '=');
	if (!split_input)
		return ;
	if (check_update_env(*env_list, split_input, input) == 0)
		return ;
	new_env = add_env(split_input);
	if (new_env == NULL)
		return ;
	new_node = ft_lstnew(new_env);
	if (!new_node)
	{
		free_env(new_env);
		split_free(split_input);
		return ;
	}
	ft_lstadd_back(env_list, new_node);
	split_free(split_input);
	sort_env_list(*env_list);
}

void	argv_export(t_cmd_list *list, t_list **env_list)
{
	int	i;

	i = 1;
	while (list->argv[i] != NULL)
	{
		if (check_export_argv(list->argv[i]) == 0)
		{
			write(2, "tontoshell: export: ", 20);
			write(2, list->argv[i], ft_strlen(list->argv[i]));
			ft_putendl_fd(": not a valid identifier", 2);
			g_status_code = 1;
			i++;
			continue ;
		}
		else
			export_main(env_list, list->argv[i]);
		i++;
	}
}

void	export(t_cmd_list *list, t_list *env_list, char **envp)
{
	t_list	*export_list;

	if (list->pid == 0)
		init_envp_list(&export_list, envp);
	else
		export_list = copy_env_list(env_list);
	sort_env_list(export_list);
	if (list->argc == 1)
		print_export_list(list, export_list);
	else
		argv_export(list, &env_list);
	free_env_list(export_list);
	g_status_code = 0;
}
