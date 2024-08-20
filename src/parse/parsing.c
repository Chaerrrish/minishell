/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/20 20:50:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*is_redirection(t_token *token_list);



int	parsing(t_shell *minishell, char *input)
{
	t_token	*token_list;
	t_token *free_temp;
	
	token_list = NULL;
	if (tokenize(minishell, &token_list, input) != 0)
		return (-1);
	token_list = is_redirection(token_list);
	// t_token *ptr = token_list;
	// while (ptr)
	// {
	// 	printf("-----------------\n");
	// 	printf("str: %s\n", ptr->str);
	// 	printf("len: %d\n", ft_strlen(ptr->str));
	// 	printf("type: %d\n", ptr->type);
	// 	ptr = ptr->next;
	// }

	minishell->cmd_list = create_cmd_list(token_list);
	
	// // !!!!! test !!!!!
	// t_cmd_list *current_cmd = minishell->cmd_list;
	// while (current_cmd != NULL)
	// {
	// 	printf("=========================================================\n");
	// 	t_token *current_token = current_cmd->token_list;
	// 	while (current_token != NULL)
	// 	{
	// 		printf("str: %s\n", current_token->str);
	// 		printf("type: %d\n", current_token->type);
	// 		current_token = current_token->next;
	// 	}

	// 	int i = 0;
	// 	printf("argc: %d\n", current_cmd->argc);
	// 	while (current_cmd->argv[i])
	// 	{
	// 		printf("argv[%d]: %s\n", i, current_cmd->argv[i]);
	// 		i++;
	// 	}
	// 	printf("=========================================================\n");
	// 	current_cmd = current_cmd->next;
	// }
	return (0);
}

t_token	*is_redirection(t_token *token_list)
{
	t_token *result;

	result = token_list;
	while (result)
	{
		if (ft_strlen(result->str) != 2 && ft_strncmp(result->str, "<<", 2) == 0)
		{
			int	i = 0;
			t_token *add;
			while (result->str[i])
				i++;
			add = ft_calloc(1, sizeof(t_token));
			add->str = ft_strdup(ft_substr(result->str, 2, i - 2));
			add->type = T_WORD;

			result->str = ft_substr(result->str, 0, 2);
			result->type = T_REDIR_HERE;
			
			add->next = result->next;
			result->next = add;
		}
		result = result->next;
	}
	return (token_list);
}
