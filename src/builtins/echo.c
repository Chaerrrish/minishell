/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/16 19:00:21 by chaerin          ###   ########.fr       */
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

void	ft_echo(t_cmd_list *list, t_list *env_list)
{
	int	i;

	i = 1;
	if (list->argc == 1)
	{
		printf("\n");
		return ;
	}
	while (list->argv[i])
	{
		if (list->argv[i][0] == '$')
			show_env(env_list, list->argv[i]);
		else
			printf("%s", list->argv[i]);
		if (list->argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}
