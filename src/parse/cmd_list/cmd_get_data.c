/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:50:40 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 20:11:06 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_argc(t_cmd_list *cmd_list);
int get_pipe_count(t_cmd_list *cmd_list);

void get_cmd_data(t_cmd_list *cmd_list)
{
	cmd_list->argc = get_argc(cmd_list);
}

int	get_argc(t_cmd_list *cmd_list)
{
	int	argc_count;

	argc_count = 0;
	while (cmd_list->token_list)
	{
		argc_count++;
		cmd_list->token_list = cmd_list->token_list->next;
	}
	return (argc_count);
}

int get_pipe_count(t_cmd_list *cmd_list)
{
	
}