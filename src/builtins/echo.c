/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 17:47:53 by chaoh            ###   ########.fr       */
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

static void	echo_argv(t_cmd_list *list, int flag)
{
	int	i;

	i = 1;
	while (list->argv[i])
	{
		if (ft_strcmp(list->argv[i], "-n") == 0)
		{
			i++;
			continue ;
		}
		else
			printf("%s", list->argv[i]);
		if (flag && list->argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
}

void	ft_echo(t_cmd_list *list, t_list *env_list)
{
	int	flag;

	flag = 1;
	if (list->argc == 1)
	{
		printf("\n");
		return ;
	}
	if (ft_strcmp(list->argv[1], "-n") == 0)
		flag = 0;
	echo_argv(list, flag);
	if (flag == 1)
		printf("\n");
}
