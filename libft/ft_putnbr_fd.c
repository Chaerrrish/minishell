/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:06 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/19 14:49:52 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_number(char *arr, int i, int fd)
{
	while (i >= 0)
	{
		write(fd, &arr[i], 1);
		if (i == 0)
			break ;
		i--;
	}
}

static void	print_int_min(int fd)
{
	write(fd, "-", 1);
	write(fd, "2", 1);
	write(fd, "147483648", 9);
}

static void	print_real_number(int nb, char *arr, int fd)
{
	int	n;
	int	i;

	i = 0;
	while (1)
	{
		n = nb % 10;
		nb = nb / 10;
		arr[i] = n + '0';
		if (nb != 0)
		{
			i++;
		}
		else if (nb == 0)
			break ;
	}
	print_number(arr, i, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[10];

	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n == -2147483648)
		print_int_min(fd);
	else
		print_real_number(n, arr, fd);
}
