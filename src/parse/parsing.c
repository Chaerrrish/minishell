/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 19:23:12 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
    t_token *token_list;

    token_list = NULL;
    if (tokenize(minishell, &token_list, input) != 0)
        return (-1);
	minishell->cmd_list = create_cmd_list(token_list);
	// !!!!! test !!!!!
	t_cmd_list *current_cmd = minishell->cmd_list;
	while (current_cmd != NULL)
	{
		printf("=========================================================\n");
		t_token *current_token = current_cmd->token_list;
		while (current_token != NULL)
		{
			printf("str: %s\n", current_token->str);
			printf("type: %d\n", current_token->type);
			current_token = current_token->next;
		}

		int i = 0;
		printf("argc: %d\n", current_cmd->argc);
		while (current_cmd->argv[i])
		{
			printf("argv[%d]: %s\n", i, current_cmd->argv[i]);
			i++;
		}
		printf("=========================================================\n");
		current_cmd = current_cmd->next;	
	}
    return (0);
}
