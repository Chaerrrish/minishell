/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/18 20:25:33 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
    t_token *token_list;

    token_list = NULL;
    if (tokenize(minishell, &token_list, input) != 0)
        return (-1);
    if (add_cmd_list(minishell, token_list) != 0)
    	return (-1);


	// // !!!!! test !!!!!
	// while (minishell->cmd_list != NULL)
	// {
	// 	while (minishell->cmd_list->token_list != NULL)
	// 	{
	// 		printf("str: %s\n", minishell->cmd_list->token_list->str);
	// 		printf("type: %d\n\n", minishell->cmd_list->token_list->type);
	// 		minishell->cmd_list->token_list = minishell->cmd_list->token_list->next;
	// 	}
	// 	printf("argc: %d\n\n", minishell->cmd_list->argc);
	// 	int i = 0;
	// 	while (minishell->cmd_list->argv[i])
	// 	{
	// 		printf("argv[%d]: %s\n", i, minishell->cmd_list->argv[i]);
	// 		i++;
	// 	}
	// 	printf("\npipe_cnt: %d\n", minishell->cmd_list->pipe_cnt);
	// 	minishell->cmd_list = minishell->cmd_list->next;	
	// }

	
    return (0);
}
