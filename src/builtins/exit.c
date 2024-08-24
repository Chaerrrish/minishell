/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:38:01 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/24 16:43:42 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_exit(t_cmd_list *cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd->argv[i])
	{
		j = 0;
		while (cmd->argv[i][j] != '\0')
		{
			if (!(cmd->argv[i][j] > '0' && cmd->argv[i][j] < '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_exit(t_cmd_list *cmd, t_list *env_list)
{
	int	exit_num;

	printf("exit\n");
	if (cmd->argv[1] == NULL)
		exit(g_status_code);
	if (check_exit(cmd) == 0)
	{
		write(2, "tontoshell: exit: ", 18);
		write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(2, ": numeric argument required\n", 28);
		exit(EXIT_FAILURE);
	}
	else if (check_exit(cmd) && cmd->argc > 2)
	{
		printf("exit\n");
		ft_putendl_fd("tontoshell: exit: too many arguments", 2);
	}
	exit_num = ft_atoi(cmd->argv[1]);
	g_status_code = exit_num;
	exit(exit_num);
}
