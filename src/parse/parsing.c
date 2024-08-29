/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/29 20:17:40 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	parsing(t_shell *minishell, char *input)
{
	t_token	*token_list;

	token_list = NULL;
	if (tokenize(minishell, &token_list, input) != 0)
	{
		free_token_list(token_list);
		return (-1);
	}
	token_list = detach_redirection(token_list);
	minishell->cmd_list = create_cmd_list(token_list);
	if (minishell->cmd_list->next != NULL)
		minishell->pipe_flag = 1;
	else
		minishell->pipe_flag = 0;
	minishell->heredoc_cnt = 0;
	free_token_list(token_list);
	return (0);
}

// t_token *ptr = token_list;
// while (ptr)
// {
// 	printf("-----------------\n");
// 	printf("str: %s\n", ptr->str);
// 	printf("len: %zu\n", ft_strlen(ptr->str));
// 	printf("type: %d\n", ptr->type);
// 	ptr = ptr->next;
// }

// // !!!!! test !!!!!
// t_cmd_list *current_cmd = minishell->cmd_list;
// while (current_cmd != NULL)
// {
// 	t_token *current_token = current_cmd->token_list;
// 	printf("=========================================================\n");
// 	printf("******************\n");
// 	while (current_token != NULL)
// 	{
// 		printf("str: %s\n", current_token->str);
// 		printf("type: %d\n", current_token->type);
// 		current_token = current_token->next;
// 	}
// 	printf("******************\n");
// 	printf("argc: %d\n", current_cmd->argc);
// 	int i = 0;
// 	while (current_cmd->argv[i])
// 	{
// 		printf("argv[%d]: %s\n", i, current_cmd->argv[i]);
// 		i++;
// 	}
// 	printf("=========================================================\n");
// 	current_cmd = current_cmd->next;
// }