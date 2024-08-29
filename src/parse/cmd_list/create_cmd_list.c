/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/29 21:16:52 by wonyocho         ###   ########.fr       */
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
			get_pipe_data(&cmd_list, &current_token);
		else
			get_cmd_data(&current_token, total_token_list, cmd_list);
		total_token_list = total_token_list->next;
	}
	cmd_list->argv = get_argv(cmd_list->token_list, cmd_list->argc);
	return (cmd_return);
}

t_cmd_list	*init_cmd_node(void)
{
	t_cmd_list	*result;

	result = ft_calloc(1, sizeof(t_cmd_list));
	if (!result)
		return (NULL);
	result->token_list = ft_calloc(1, sizeof(t_token));
	result->argc = 0;
	result->argv = NULL;
	result->in_fd = STDIN_FILENO;
	result->out_fd = STDOUT_FILENO;
	result->pipe_fd[0] = -1;
	result->pipe_fd[1] = -1;
	result->heredoc_file = NULL;
	result->path = NULL;
	result->pid = -1;
	return (result);
}
