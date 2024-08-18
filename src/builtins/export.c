/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:27:13 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/18 17:25:18 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_update_env(t_list *env_list, char **split_input, char *input)
{
	t_env	*new_env;
	t_list 	*current;

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

t_env	*add_env(t_list *env_list, char **split_input, char	*input)
{
	t_env	*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
	{
		split_free(split_input);
		return (NULL);
	}
	new_env->key = ft_strdup(split_input[0]);
	if (split_input[1] != NULL)
		new_env->value = ft_strdup(split_input[1]);
	else
		new_env->value = ft_strdup("");
	new_env->data = ft_strdup(input);
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
	if (check_update_env(env_list, split_input, input) == 0)
		return ;
	new_env = add_env(env_list, split_input, input);
	if (new_env == NULL)
		return ;
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
	split_free(split_input);
	sort_export_list(*env_list);
}

void	print_export_list(t_list *env_list)
{
	t_list	*current;
	t_env	*node;

	current = env_list;
	while (current != NULL)
	{
		node = (t_env *)current->content;
		printf("declare -x %s\n", node->data);
		current = current->next;
	}
}

void	argv_export(t_ASTNode *tree, t_list **env_list)
{
	int	i;

	i = 0;
	while (tree->cmd->argv[i] != NULL)
	{
		if (check_builtin_argv(tree->cmd->argv[i]) == 0)
		{
			write(2, "tontoshell: export: ", 20);
			wirte(2, tree->cmd->argv[i], ft_strlen(tree->cmd->argv[i]));
			ft_putendl_fd(": not a valid identifier", 2);
			i++;
			continue ;
		}
		else
			export_main(env_list, tree->cmd->argv[i]);
		i++;
	}
}

void	export(t_ASTNode *tree, t_list *env_list)
{
	t_list	*export_list;
	t_env	*node;

	export_list = copy_env_list(env_list);
	sort_export_list(export_list);
	if (tree->cmd->argv[0] == NULL)
		print_export_list(export_list);	
	else
		argv_export(tree, &export_list);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_list *lst;

// 	init_envp_lst(&lst, envp);
// 	// export(lst);
// 	show_env(lst, "HI=hi");
// 	return (0);
// }

