/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:23:54 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/29 18:09:43 by chaoh            ###   ########.fr       */
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

void	sort_env_list(t_list *export_list)
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
		free_env(new_env);
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
		new_node = ft_lstnew(new_env);
		if (new_env == NULL || new_node == NULL)
		{
			free_env(new_env);
			free_env_list(new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}

void	print_export_list(t_cmd_list *list, t_list *env_list)
{
	t_list	*current;
	t_env	*node;

	current = env_list;
	while (current != NULL)
	{
		node = (t_env *)current->content;
		if (ft_strlen(node->value) != 0)
		{
			write(list->out_fd, "declare -x ", 11);
			write(list->out_fd, node->key, ft_strlen(node->key));
			write(list->out_fd, "=\"", 2);
			write(list->out_fd, node->value, ft_strlen(node->value));
			write(list->out_fd, "\"\n", 2);
		}
		else
		{
			write(list->out_fd, "declare -x ", 11);
			write(list->out_fd, node->key, ft_strlen(node->key));
			write(list->out_fd, "\n", 1);
		}
		current = current->next;
	}
}
