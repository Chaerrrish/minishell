/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 20:30:15 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
	t_token	*token_list;

	token_list = NULL;
	if (tokenize(minishell, &token_list, input) != 0)
		return (-1);
	printf("%s\n", minishell->cmd_list);
	if (add_cmd_list(&(minishell->cmd_list), &token_list) != 0)
		return (-1);
	printf("%s\n", minishell->cmd_list->token_list->str);
	token_lst_free(token_list);
	return (0);
}
