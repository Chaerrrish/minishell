/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:36:56 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 19:15:33 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	split_free(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	token_free(t_token *token)
{
	if (token->str)
		free(token->str);
	free(token);
}
