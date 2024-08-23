/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/22 19:25:10 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list	*create_cmd_list(t_token *total_token_list)
{
	t_cmd_list	*cmd_list;
	t_cmd_list	*cmd_return;
	t_token		*current_token;

	cmd_list = init_cmd_node();
	cmd_return = cmd_list;
	current_token = cmd_list->token_list;
	while (total_token_list != NULL)
	{
		if (ft_strcmp(total_token_list->str, "|") == 0)
		{
			cmd_list->argv = get_argv(cmd_list->token_list, cmd_list->argc);
			cmd_list->next = init_cmd_node();
			cmd_list = cmd_list->next;
			current_token = cmd_list->token_list;
		}
		else // 현재가 파이프가 아닐경우
		{
			current_token->str = ft_strdup(total_token_list->str);
			current_token->type = get_token_type(current_token->str);

			cmd_list->argc++;
			if (ft_strcmp(current_token->str, "<") == 0 || ft_strcmp(current_token->str, ">") == 0
				|| ft_strcmp(current_token->str, ">>") == 0 || ft_strcmp(current_token->str, "<<") == 0)
			{
				cmd_list->argc--;
				if (total_token_list->next != NULL)
					cmd_list->argc--;
			}

			if (total_token_list->next != NULL)
			{
				if (ft_strcmp(total_token_list->next->str, "|") != 0)
				{
					current_token->next = ft_calloc(1, sizeof(t_token));
					current_token = current_token->next;
				}
			}
		}
		total_token_list = total_token_list->next;
	}
	cmd_list->argv = get_argv(cmd_list->token_list, cmd_list->argc);
	return (cmd_return);
}

t_cmd_list *init_cmd_node(void)
{
	t_cmd_list *result;

	result = ft_calloc(1, sizeof(t_cmd_list));
	if (!result)
		return (NULL);
	result->token_list = ft_calloc(1, sizeof(t_token));
	result->argc = 0;
	result->argv = NULL;
	result->in_fd = -1;
	result->out_fd = -1;
	result->pipe_fd[0] = -1;
	result->pipe_fd[1] = -1;
	result->heredoc_file = NULL;
	result->path = NULL;
	result->pid = 0;
	return (result);
}

char **get_argv(t_token *token_list, int size)
{
	t_token	*cur;
	char	**result;
	int		i;

	result = ft_calloc(size + 1, sizeof(char *));
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
