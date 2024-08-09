/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/09 13:22:09 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 머 넘겨주지
// 1. 일단 덩어리들?
// 2. 파이프 유무?
// 3. 따옴표 제대로 닫았나 확인?

#include "minishell.h"

int	parsing(t_shell *minishell, char *input)
{
	t_token	*token_lst;
	int		result;

	token_lst = NULL; 
	result = tokenize(minishell, token_lst, input);

}