/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:36:55 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing(t_shell *minishell, char *input)
{
	t_token	*token_lst;
	int		result;

	if (check_quotes(input) == -1) // 짝이 맞는지 검사.
		return (-1); // 에러 -1.
	token_lst = NULL;
	result = tokenize(minishell, token_lst, input);

}