/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/17 00:01:50 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list *create_new_cmd_list(t_token *token_list)
{
    t_cmd_list *new_cmd_list;

    new_cmd_list = (t_cmd_list *)malloc(sizeof(t_cmd_list));
    if (!new_cmd_list)
        return (NULL);
    new_cmd_list->token_list = token_list;
    new_cmd_list->argc = 0;
    new_cmd_list->argv = NULL;
    new_cmd_list->pipe_cnt = 0;
    new_cmd_list->next = NULL;
    return (new_cmd_list);
}

int add_cmd_list(t_shell *minishell, t_token *token_list)
{
    t_cmd_list *new_cmd;
    t_cmd_list *current;

    new_cmd = create_new_cmd_list(token_list);
    if (!new_cmd)
        return (-1);
    if (minishell->cmd_list == NULL)
        minishell->cmd_list = new_cmd;
    else
    {
        current = minishell->cmd_list;
        while (current->next != NULL)
            current = current->next;
        current->next = new_cmd;
    }
    if (get_cmd_data(minishell->cmd_list) != 0)
        return (-1);
    return (0);
}
