/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:38:01 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/25 19:52:41 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	check_exit(t_cmd_list *cmd)
{
	if (check_exit_argv(cmd) == 0)
	{
		write(2, "tontoshell: exit: ", 18);
		write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(2, ": numeric argument required\n", 28);
		g_status_code = 255;
		if (cmd->pid == 0)
			return ;
		exit(255);
	}
	else if (check_exit_argv(cmd) && cmd->argc > 2)
	{
		ft_putendl_fd("tontoshell: exit: too many arguments", 2);
		g_status_code = 1;
		if (cmd->pid == 0)
			return ;
		exit(1);
	}
}

void	ft_exit(t_cmd_list *cmd)
{
	int	exit_num;

	if (cmd->pid > 0)
		write(cmd->out_fd, "exit\n", 5);
	check_exit(cmd);
	if (cmd->argv[1] == NULL)
		exit(g_status_code);
	exit_num = ft_atoi(cmd->argv[1]);
	if (exit_num > 255)
		exit_num = 255;
	g_status_code = exit_num;
	exit(exit_num);
}
