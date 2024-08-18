/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 23:11:40 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *minishell, char *input)
{
    t_token *token_list;

    token_list = NULL;
    if (tokenize(minishell, &token_list, input) != 0)
        return (-1);
    if (add_cmd_list(minishell, token_list) != 0)
		return (-1);
    return (0);
}
