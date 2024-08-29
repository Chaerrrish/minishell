/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:54:47 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/29 15:57:00 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_argc(t_cmd_list *cmd_list, t_token *lst, t_token *total)
{
	cmd_list->argc++;
	if (ft_strcmp(lst->str, "<") == 0 || ft_strcmp(lst->str, ">") == 0
		|| ft_strcmp(lst->str, ">>") == 0 || ft_strcmp(lst->str, "<<") == 0)
	{
		cmd_list->argc--;
		if (total->next != NULL)
			cmd_list->argc--;
	}
}

char	**get_argv(t_token *token_list, int size)
{
	t_token	*cur;
	char	**result;
	int		i;

	result = ft_calloc(size + 1, sizeof(char *));
	if (!result)
		memory_error();
	i = 0;
	cur = token_list;
	while (cur && i < size)
	{
		if ((ft_strcmp(cur->str, ">") == 0) || (ft_strcmp(cur->str, "<") == 0)
			|| ft_strcmp(cur->str, ">>") == 0 || ft_strcmp(cur->str, "<<") == 0)
			cur = cur->next->next;
		result[i] = ft_strdup(cur->str);
		i++;
		cur = cur->next;
	}
	result[i] = NULL;
	return (result);
}

void	get_cmd_data(t_token **current, t_token *total, t_cmd_list *cmd)
{
	(*current)->str = ft_strdup(total->str);
	if ((*current)->str == NULL)
		memory_error();
	(*current)->type = get_token_type((*current)->str);
	get_argc(cmd, *current, total);
	if (total->next != NULL)
	{
		if (ft_strcmp(total->next->str, "|") != 0)
		{
			(*current)->next = ft_calloc(1, sizeof(t_token));
			*current = (*current)->next;
		}
	}
}

void	get_pipe_data(t_cmd_list **cmd_list, t_token **current_token)
{	
	(*cmd_list)->argv = get_argv((*cmd_list)->token_list, (*cmd_list)->argc);
	(*cmd_list)->next = init_cmd_node();
	*cmd_list = (*cmd_list)->next;
	*current_token = (*cmd_list)->token_list;
}
