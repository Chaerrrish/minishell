/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/16 20:32:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	show_env(t_list *env_list, char *input)
{
	t_list	*current;
	t_env	*node;

	current = env_list;
	if (*input == '$')
		input++;
	while (current)
	{
		node = (t_env *)current->content;
		if (ft_strcmp(node->key, input) == 0)
		{
			printf("%s", node->value);
			return ;
		}
		current = current->next;
	}
}

void	ft_echo(t_ASTNode *tree, t_list *env_list)
{
	int	i;

	i = 0;
	if (tree->cmd->argv == NULL)
	{
		printf("\n");
		return ;
	}
	while (tree->cmd->argv[i])
	{
		if (tree->cmd->argv[i][0] == '$')
			show_env(env_list, tree->cmd->argv[i]);
		else
			printf("%s", tree->cmd->argv[i]);
		if (tree->cmd->argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}
