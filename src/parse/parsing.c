/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 22:47:08 by wonyocho         ###   ########.fr       */
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
	if (token_list != NULL)
		free_token_list(token_list);
	return (0);
}
