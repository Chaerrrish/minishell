/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 20:29:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_cmd_list(t_cmd_list **cmd_list, t_token **current_token_list)
{
    t_cmd_list *new_cmd_list;
    t_cmd_list *last_cmd_list;

    new_cmd_list = malloc(sizeof(t_cmd_list));
    if (!new_cmd_list)
        return (-1);

    new_cmd_list->token_list = current_token_list;
    new_cmd_list->next = NULL;
    if (*cmd_list == NULL) // cmd_list가 NULL인 경우, 새로 생성한 리스트를 할당
    {
        *cmd_list = new_cmd_list;
    }
    else
    {
        last_cmd_list = *cmd_list;
        while (last_cmd_list->next) // 맨 끝으로 이동
            last_cmd_list = last_cmd_list->next;
        last_cmd_list->next = new_cmd_list; // 마지막 노드의 next를 새로운 노드로 설정
    }
    printf("cmd->token->str: %s\n", (*cmd_list)->token_list->str);
    printf("new->token->str: %s\n", new_cmd_list->token_list->str);
    get_cmd_data(new_cmd_list);
    return (0);
}
