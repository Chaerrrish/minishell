/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/06 20:17:27 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_new_cmd()
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd_line = NULL;
	new_cmd->pipe_flag = 0;
	new_cmd->single_quote = 0;
	new_cmd->double_quote = 0;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	tokenize(t_cmd *cmd, char *str)
{
	cmd->single_quote = check_single_quotes(str);
	cmd->double_quote = check_double_quotes(str);
	cmd->cmd_line = ft_split(str, ' ');
	if (ft_strchr(str, '|'))
		cmd->pipe_flag = 1;
	else
		cmd->pipe_flag = 0;
}
