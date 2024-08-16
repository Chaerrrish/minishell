/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 18:43:47 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_cmd_list(t_shell *minishell, t_list *current_token_list)
{
	while (minishell->cmd_list) // 맨뒤로 이동
		minishell->cmd_list = minishell->cmd_list->next;
	minishell->cmd_list->token_list = current_token_list;
	return (0);
}