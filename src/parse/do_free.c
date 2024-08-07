/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:23:33 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/07 12:31:54 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_free(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd != NULL)
	{
		tmp = cmd->next;
		i = 0;
		while (cmd->cmd_line[i] != NULL)
		{
			free(cmd->cmd_line[i]);
			i++;
		}
		free(cmd->cmd_line);
		free(cmd);
		cmd = tmp;
	}
}
