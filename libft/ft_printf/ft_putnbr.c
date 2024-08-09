/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:06 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:21:00 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number(char *arr, int i, int fd, int cnt)
{
	while (i >= 0)
	{
		if (write(fd, &arr[i], 1) < 0)
			return (-1);
		cnt++;
		if (i == 0)
			break ;
		i--;
	}
	return (cnt);
}

static int	print_real_number(int nb, char *arr, int fd, int cnt)
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
			i++;
		else if (nb == 0)
			break ;
	}
	cnt = print_number(arr, i, fd, cnt);
	return (cnt);
}

int	ft_putnbr(int n, int fd, int cnt)
{
	char	arr[10];

	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		cnt++;
		if (write(fd, "-", 1) < 0)
			return (-1);
	}
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			return (-1);
		cnt += 11;
	}
	else
		cnt = print_real_number(n, arr, fd, cnt);
	return (cnt);
}

int	ft_putunbr(unsigned int nb, int cnt)
{
	char			arr[10];
	int				i;

	i = 0;
	if (nb == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		cnt++;
	}
	while (nb != 0)
	{
		arr[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (write(1, &arr[i], 1) < 0)
			return (-1);
		i--;
		cnt++;
	}
	return (cnt);
}
