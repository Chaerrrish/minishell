/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:45:58 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/29 18:06:52 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_export_argv(char	*str)
{
	int	i;

	i = 1;
	if (!(str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') \
		|| (str[0] >= 'A' && str[0] <= 'Z')))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') \
		|| (str[i] >= 'A' && str[i] <= 'Z') \
		|| (str[i] >= '0' && str[i] <= '9') \
		|| (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

int	check_unset_argv(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') \
		|| (str[0] >= 'A' && str[0] <= 'Z')))
		return (0);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') \
		|| (str[i] >= 'A' && str[i] <= 'Z') \
		|| (str[i] >= '0' && str[i] <= '9') \
		|| (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_argv(t_cmd_list *cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd->argv[i])
	{
		j = 0;
		while (cmd->argv[i][j] != '\0')
		{
			if (!(cmd->argv[i][j] >= '0' && cmd->argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
