/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:17 by chaoh             #+#    #+#             */
/*   Updated: 2023/11/20 00:19:39 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_address(unsigned long long addr, int cnt)
{
	int			i;
	const char	*hex = "0123456789abcdef";
	int			arr[16];

	i = 1;
	while (addr > 0)
	{
		arr[16 - i] = addr % 16;
		addr = addr / 16;
		i++;
	}
	i = 16 - i + 1;
	while (i < 16)
	{
		if (write(1, &hex[arr[i]], 1) == -1)
			return (-1);
		cnt++;
		i++;
	}
	return (cnt);
}

int	get_address(va_list ap, int cnt)
{
	unsigned long long	addr;
	void				*p;

	if (write(1, "0x", 2) < 0)
		return (-1);
	cnt += 2;
	p = va_arg(ap, void *);
	if (p == NULL)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		cnt++;
		return (cnt);
	}
	addr = (unsigned long long)p;
	cnt = print_address(addr, cnt);
	return (cnt);
}

int	print_hex_low(va_list ap, int cnt)
{
	const char		*hex_low = "0123456789abcdef";
	int				arr[16];
	int				i;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	i = -1;
	if (n == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		cnt++;
	}
	while (n > 0)
	{
		arr[++i] = n % 16;
		n = n / 16;
	}
	while (i >= 0)
	{
		if (write(1, &hex_low[arr[i--]], 1) < 0)
			return (-1);
		cnt++;
	}
	return (cnt);
}

int	print_hex_up(va_list ap, int cnt)
{
	const char		*hex_up = "0123456789ABCDEF";
	int				arr[16];
	int				i;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	i = -1;
	if (n == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		cnt++;
	}
	while (n > 0)
	{
		arr[++i] = n % 16;
		n = n / 16;
	}
	while (i >= 0)
	{
		if (write(1, &hex_up[arr[i--]], 1) < 0)
			return (-1);
		cnt++;
	}
	return (cnt);
}
