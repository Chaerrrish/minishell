/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:50:40 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/20 16:00:02 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_argc(t_token *token_list)
{
	int		argc_count;
	t_token	*current;

	argc_count = 0;
	current = token_list;
	while (current != NULL && ft_strcmp(current->str, "|") != 0)
	{
		argc_count++;
		current = current->next;
	}
	return (argc_count);
}

int	get_argv(t_cmd_list *cmd_list, int size)
{
	t_token	*current;
	int		i;

	cmd_list->argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (!cmd_list->argv)
		return (-1);
	current = cmd_list->token_list;
	i = 0;
	while (current != NULL && ft_strcmp(current->str, "|") != 0)
	{
		cmd_list->argv[i] = ft_strdup(current->str);
		if (!cmd_list->argv[i])
			return (-1);
		i++;
		current = current->next;
	}
	cmd_list->argv[i] = NULL;
	return (0);
}

int	get_cmd_data(t_cmd_list *cmd_list, t_token *token_list)
{
	cmd_list->argc = get_argc(cmd_list->token_list);
	if (get_argv(cmd_list, cmd_list->argc) != 0)
		return (-1);
	return (0);
}
