/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:41:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/27 19:12:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static t_env	*new_env_node(void)
{
	t_env	*result;

	result = (t_env *)malloc(sizeof(t_env));
	if (!result)
		return (NULL);
	result->data = NULL;
	result->key = NULL;
	result->value = NULL;
	return (result);
}

static char	*get_key(char *data)
{
	int		i;
	char	*result;

	i = 0;
	while (data[i] != '=' && data[i])
		i++;
	result = ft_substr(data, 0, i);
	return (result);
}

static char	*get_value(char *data)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(data);
	while (data[i] != '=' && data[i])
		i++;
	result = ft_substr(data, i + 1, len - i);
	return (result);
}

static t_env	*get_data_key_value(t_env *env, char **envp)
{
	env->data = ft_strdup(*envp);
	env->key = get_key(env->data);
	env->value = get_value(env->data);
	return (env);
}

void	init_envp_list(t_list **lst, char **envp)
{
	t_env	*env;
	t_list	*tmp;

	*lst = NULL;
	while (*envp)
	{
		env = new_env_node();
		if (!env)
		{
			perror("envp init failed\n");
			exit(1);
		}
		env = get_data_key_value(env, envp);
		tmp = ft_lstnew(env);
		if (!tmp)
		{
			free_env_list(*lst);
			perror("malloc failed\n");
			exit(1);
		}
		ft_lstadd_back(lst, tmp);
		envp++;
	}
}
