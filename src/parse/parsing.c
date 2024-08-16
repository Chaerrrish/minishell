/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 18:38:02 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
	t_token	*token_list;

	token_list = NULL;
	if (tokenize(minishell, &token_list, input) != 0)
		return (-1);

	// todo
	// 1. mini->cmd_list에 이제 추가.
	if (add_cmd_list(minishell, &token_list) != 0)
		return (-1);

	
	token_lst_free(token_list);
	return (0);
}
