/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/20 14:58:20 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	show_env(t_list *env_list, char *input, int *flag)
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
	*flag = 0;
}

void	ft_echo(t_cmd_list *list, t_list *env_list)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	if (ft_strcmp(list->argv[1], "-n") == 0)
		flag = 0;
	if (list->argc == 1)
	{
		printf("\n");
		return ;
	}
	while (list->argv[i])
	{
		// if (list->argv[i][0] == '$')
		// 	show_env(env_list, list->argv[i], &flag);
		if (ft_strcmp(list->argv[i], "-n") == 0)
		{
			i++;
			continue;
		}
		else
			printf("%s", list->argv[i]);
		if (flag && list->argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (flag == 1)
		printf("\n");
}
