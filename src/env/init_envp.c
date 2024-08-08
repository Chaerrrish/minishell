/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:41:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/08 16:13:36 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*get_env()
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
	// "PATH=/usr/bin:/bin" 이런식이란 말이지..
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

// envp에서 key, value 추출해서 리스트 만들기
void	init_envp_lst(t_list *lst, char **envp)
{
	t_env	*env;
	t_list	*tmp;
	
	lst = NULL;
	while (*envp)
	{
		env = get_env();
		if (!env)
		{
			perror("envp init failed\n");
			exit(1);
		}
		env = get_data_key_value(env, envp);
		tmp = ft_lstnew(env);
		if (!tmp)
		{
			lst_free(lst);
			perror("malloc failed\n");
			exit(1);
		}
		ft_lstadd_back(&lst, tmp);
		envp++;
	}
}
