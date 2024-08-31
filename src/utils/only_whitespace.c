/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:19:36 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/31 11:37:02 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	only_whitespace(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\t')
			return (0);
		i++;
	}
	return (-1);
}

static int	check_syntax_error(char *input, int i, char *pattern,
								char *message)
{
	if (ft_strncmp(&input[i], pattern, ft_strlen(pattern)) == 0)
	{
		ft_putendl_fd(message, 2);
		return (-1);
	}
	return (0);
}

int	check_redir_in_a_row(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (check_syntax_error(input, i, "<<<",
				"tontoshell: syntax error near unexpected token '<<<'") == -1
			|| check_syntax_error(input, i, ">>>",
				"tontoshell: syntax error near unexpected token '>>>'") == -1
			|| check_syntax_error(input, i, "<>",
				"tontoshell: syntax error near unexpected token '<>'") == -1
			|| check_syntax_error(input, i, "><",
				"tontoshell: syntax error near unexpected token '><'") == -1)
		{
			g_status_code = 258;
			return (-1);
		}
		i++;
	}
	return (0);
}
