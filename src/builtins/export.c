/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:27:13 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/14 16:04:44 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	swap_content(t_list *a, t_list *b)
{
	t_env	tmp;

	tmp = *(t_env *)a->content;
	*(t_env *)a->content = *(t_env *)b->content;
	*(t_env *)b->content = tmp;
}

void	sort_export_list(t_list *export_list)
{
	t_list	*i;
	t_list	*j;
	t_env	*i_con;
	t_env	*j_con;

	if (export_list == NULL)
		return ;
	i = export_list;
	while (i)
	{
		i_con = (t_env *)i->content;
		j = i->next;
		while (j)
		{
			j_con = (t_env *)j->content;
			if (ft_strcmp(i_con->key, j_con->key) > 0)
				swap_content(i, j);
			j = j->next;
		}
		i = i->next;
	}
}

t_env	*copy_env(t_env *env)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
		return (NULL);
	new_env->data = ft_strdup(env->data);
	new_env->key = ft_strdup(env->key);
	new_env->value = ft_strdup(env->value);
	if (!new_env->data || !new_env->key || !new_env->value)
	{
		free(new_env->data);
		free(new_env->key);
		free(new_env->value);
		free(new_env);
		return (NULL);
	}
	return (new_env);
}

t_list	*copy_env_list(t_list *env_list)
{
	t_list	*new_list;
	t_list	*current;
	t_env	*new_env;
	t_list	*new_node;

	new_list = NULL;
	current = env_list;

	while (current != NULL)
	{
		new_env = copy_env((t_env *)current->content);
		if (new_env == NULL)
			return (NULL);
		new_node = ft_lstnew(new_env);
		if (new_node == NULL)
			return (NULL);
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}

void export(t_list *env_list)
{
	t_list	*export_list;
	t_list	*current;
	t_env	*node;

	export_list = copy_env_list(env_list);
	sort_export_list(export_list);
	current = export_list;
	while (current != NULL)
	{
		node = (t_env *)current->content;
		printf("%s\n", node->data);
		current = current->next;
	}
}

// int main(int ac, char **av, char **envp)
// {
// 	t_list *lst;

// 	init_envp_lst(&lst, envp);
// 	export(lst);
// 	return (0);
// }

