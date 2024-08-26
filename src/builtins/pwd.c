/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:55 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/26 17:07:37 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	pwd(t_cmd_list *cmd)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str != NULL)
		ft_putendl_fd(str, cmd->out_fd);
	else
		perror("pwd");
	free(str);
	g_status_code = 0;
}
