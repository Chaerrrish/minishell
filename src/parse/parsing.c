/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 17:09:39 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
    t_token *token_list;

    token_list = NULL;
    if (tokenize(minishell, &token_list, input) != 0)
        return (-1);
	minishell->cmd_list = create_cmd_list_from_tokens(token_list);
    return (0);
}

	// // !!!!! test !!!!!
	// while (minishell->cmd_list != NULL)
	// {
	// 	printf("new command~!\n");
	// 	while (minishell->cmd_list->token_list != NULL)
	// 	{
	// 		printf("str: %s\n", minishell->cmd_list->token_list->str);
	// 		printf("type: %d\n", minishell->cmd_list->token_list->type);
	// 		minishell->cmd_list->token_list = minishell->cmd_list->token_list->next;
	// 	}
	// 	int i = 0;
	// 	printf("argc: %d\n", minishell->cmd_list->argc);
	// 	while (minishell->cmd_list->argv[i])
	// 	{
	// 		printf("argv[%d]: %s\n", i, minishell->cmd_list->argv[i]);
	// 		i++;
	// 	}
	// 	minishell->cmd_list = minishell->cmd_list->next;	
	// }
