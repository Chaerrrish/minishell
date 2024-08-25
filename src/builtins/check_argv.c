/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:45:58 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/25 15:47:53 by chaoh            ###   ########.fr       */
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
		|| (str[i] >= '0' && str[i] <='9') \
		|| (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

int check_unset_argv(char *str)
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
		|| (str[i] >= '0' && str[i] <='9') \
		|| (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}
