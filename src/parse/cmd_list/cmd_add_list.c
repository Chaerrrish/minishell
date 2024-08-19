/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 17:10:10 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list	*create_cmd_node(t_token *start_token, int argc)
{
	t_cmd_list	*new_cmd;
	t_token 	*temp_token;
	int			i;

	new_cmd = malloc(sizeof(t_cmd_list));
	if (!new_cmd)
		return (NULL);
	temp_token = start_token;
	new_cmd->token_list = start_token;
	new_cmd->argc = argc;
	new_cmd->argv = malloc((argc + 1) * sizeof(char *));
	i = 0;
	while (temp_token && i < argc)
	{
		new_cmd->argv[i++] = strdup(temp_token->str);
		temp_token = temp_token->next;
	}
	new_cmd->argv[argc] = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	add_cmd_node(t_cmd_list **cmd_list, t_cmd_list *new_cmd)
{
	t_cmd_list *current_cmd;

	current_cmd = *cmd_list;
	if (!current_cmd)
		*cmd_list = new_cmd;
	else
	{
		while (current_cmd->next)
			current_cmd = current_cmd->next;
		current_cmd->next = new_cmd;
	}
}

t_token	*create_token_list_from_argv(char **argv, int argc)
{
	t_token *result;
	t_token *current_token;
	t_token *new_token;
	int		i;

	result = NULL;
	current_token = NULL;
	i = 0;
	while (i < argc)
	{
		new_token = malloc(sizeof(t_token));
		if (!new_token)
			return (NULL);
		new_token->str = strdup(argv[i]);
		new_token->type = get_token_type(argv[i]);
		new_token->next = NULL;
		if (!result)
			result = new_token;
		else
			current_token->next = new_token;
		current_token = new_token;
		i++;
	}
	return (result);
}

t_cmd_list	*create_cmd_list_from_tokens(t_token *token_list)
{
	t_cmd_list	*cmd_list;
	t_token		*start_token;
	int			argc;

	cmd_list = NULL;
	start_token = token_list;
	argc = 0;
	while (token_list)
	{
		if (token_list->type == T_PIPE)
		{
			add_cmd_node(&cmd_list, create_cmd_node(start_token, argc));
			cmd_list->token_list = create_token_list_from_argv(cmd_list->argv, cmd_list->argc);
			start_token = token_list->next;
			argc = 0;
		}
		else
			argc++;
		token_list = token_list->next;
	}
	if (start_token)
	{
		add_cmd_node(&cmd_list, create_cmd_node(start_token, argc));
		cmd_list->token_list = create_token_list_from_argv(cmd_list->argv, cmd_list->argc);
	}
	return (cmd_list);
}
