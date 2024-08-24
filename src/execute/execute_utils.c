/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:34:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/24 17:59:17 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	set_status_code(int status)
{
	g_status_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			g_status_code = 130;
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			g_status_code = 131;
		}
		else
			g_status_code = 128 + status;
	}
}