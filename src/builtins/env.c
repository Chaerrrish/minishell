/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:33:11 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/13 21:29:23 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	env(t_ASTNode *tree, t_list *env_list)
{
	t_env	*env;
	t_list	*current;

	current = env_list;
	if (tree->cmd->argv[0] != NULL)
	{
		printf("env: %s: No such file or directory\n", tree->cmd->argv[0]);
		return ;
	}
	while (current != NULL)
	{
		env = (t_env *)current->content;
		if (ft_strlen(env->value) != 0)
			printf("%s=%s\n", env->key, env->value);
		current = current->next;
	}
}

// int main(int ac, char **av, char **envp)
// {
// 	t_list *lst;

// 	init_envp_lst(&lst, envp);
// 	env(lst);
// 	return (0);
// }
