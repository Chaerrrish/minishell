/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:25 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/26 17:24:06 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	check_option(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	echo_argv(t_cmd_list *list, int start_index)
{
	int	i;

	i = start_index;
	while (list->argv[i])
	{
		write(list->out_fd, list->argv[i], ft_strlen(list->argv[i]));
		if (list->argv[i + 1] != NULL)
			write(list->out_fd, " ", 1);
		i++;
	}
}

void	ft_echo(t_cmd_list *list)
{
	int	flag;
	int	i;

	flag = 1;
	i = 1;
	if (list->argc == 1)
	{
		write(list->out_fd, "\n", 1);
		return ;
	}
	while (list->argv[i] && check_option(list->argv[i]))
	{
		flag = 0;
		i++;
	}
	echo_argv(list, i);
	if (flag == 1)
		write(list->out_fd, "\n", 1);
	g_status_code = 0;
}
