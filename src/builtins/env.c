/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:33:11 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/16 20:32:08 by wonyocho         ###   ########.fr       */
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
		write(2, "env: ", 5);
		write(2, tree->cmd->argv[0], ft_strlen(tree->cmd->argv[0]));
		ft_putendl_fd(": No such file or directory", 2);
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
