/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:47 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/24 15:04:38 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	value;
	long long	flag;

	i = 0;
	flag = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(value * flag));
}
/*
#include <stdio.h>
#include <stdlib.h>
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("%d\n", ft_atoi(av[1]));
// 	printf("%d\n", atoi(av[1]));
// 	return (0);
// }
*/