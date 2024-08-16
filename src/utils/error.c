/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:02 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/14 15:57:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	memory_error(void)
{
	ft_putendl_fd("error: memory allocation error", STDERR_FILENO);
	g_status_code = 137;
	exit(137);
}
