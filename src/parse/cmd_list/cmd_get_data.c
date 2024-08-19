/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:50:40 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 16:21:18 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_argc(t_token *token_list)
{
	int argc_count;
	t_token *current = token_list;

	argc_count = 0;
	while (current != NULL && ft_strcmp(current->str, "|") != 0)
	{
		argc_count++;
		current = current->next;
	}
	return (argc_count);
}

int get_argv(t_cmd_list *cmd_list, int size)
{
    int i;
    t_token *current;

    cmd_list->argv = (char **)malloc(sizeof(char *) * (size + 1));
    if (!cmd_list->argv)
        return (-1);
    current = cmd_list->token_list;
    i = 0;
	while (current != NULL && ft_strcmp(current->str, "|") != 0)
    {
        cmd_list->argv[i] = ft_strdup(current->str);  // strdup을 사용하여 문자열 복사
        if (!cmd_list->argv[i])
            return (-1);
        i++;
        current = current->next;
    }
    cmd_list->argv[i] = NULL; // 마지막에 NULL 포인터를 추가
	return (0);
}

int get_cmd_data(t_cmd_list *cmd_list, t_token *token_list) // pipe만 하나 있는 cmd list, | 뒤에 아무것도 없으면 syntax error
{
	cmd_list->argc = get_argc(cmd_list->token_list);
	if (get_argv(cmd_list, cmd_list->argc) != 0)
		return (-1);
	return (0);
}
