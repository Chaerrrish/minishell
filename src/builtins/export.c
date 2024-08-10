/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:27:13 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/10 17:04:55 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	add_env(t_list *env_list, char *input)
{
	t_env	*new_env;
	t_list	*new_node;
	char	**split_input;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
		return ;
	split_input = ft_split(input, '=');
	if (!split_input)
	{
		free(new_env);
		return ;
	}
	new_env->data = ft_strdup(input);
	new_env->key = ft_strdup(split_input[0]);
	if (split_input[1] == NULL)
		new_env->value=ft_strdup("");
	new_env->value = ft_strdup(split_input[1]);
	new_node = ft_lstnew(new_env);
	if (!new_node)
	{
		free(new_env->data);
		free(new_env->key);
		free(new_env->value);
		free(new_env);
		split_free(split_input);
		return ;
	}
	ft_lstadd_back(&env_list, new_node);
	// split_free(split_input);
}

void	show_env(t_list *env_list, char *input)
{
	t_list	*current;
	t_env	*node;

	current = env_list;
	while (current)
	{
		node = (t_env *)current->content;
		if (ft_strcmp(node->key, input) == 0)
			printf("%s\n", node->data);
		else
			add_env(env_list, input);
		current = current->next;
	}
}

void	export(t_list *env_list)
{
	t_list	*export_list;
	t_list	*current;
	t_env	*node;
	int		param_flag;

	param_flag = 0;
	export_list = copy_env_list(env_list);
	sort_export_list(export_list);
	current = export_list;
	if (param_flag == 0)
	{
		while (current != NULL)
		{
			node = (t_env *)current->content;
			printf("declare -x %s\n", node->data);
			current = current->next;
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_list *lst;

	init_envp_lst(&lst, envp);
	// export(lst);
	show_env(lst, "HI=hi");
	return (0);
}

