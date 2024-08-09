/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:42:30 by chaoh             #+#    #+#             */
/*   Updated: 2023/11/12 17:01:17 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_percent(int cnt)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	cnt++;
	return (cnt);
}

static int	change(va_list ap, const char *format, int cnt)
{
	int	tmp;

	tmp = cnt;
	if (*format == 'c')
		return (print_char(ap, cnt));
	else if (*format == 's')
		cnt = print_str(ap, cnt);
	else if (*format == 'p')
		cnt = get_address(ap, cnt);
	else if (*format == 'd')
		cnt = print_dec(ap, cnt);
	else if (*format == 'i')
		cnt = print_dec(ap, cnt);
	else if (*format == 'u')
		cnt = print_unsigned(ap, cnt);
	else if (*format == 'x')
		cnt = print_hex_low(ap, cnt);
	else if (*format == 'X')
		cnt = print_hex_up(ap, cnt);
	else if (*format == '%')
		cnt = print_percent(cnt);
	if (tmp > cnt)
		return (-1);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			cnt = change(ap, format, cnt);
			if (cnt == -1)
				return (-1);
			format++;
		}
		else
		{
			if (write(1, format, 1) < 0)
				return (-1);
			format++;
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}

// int main(void)
// {
// 	printf("%d\n", ft_printf("%x", 100));
// 	printf("%d\n", ft_printf("%%%c", 'x'));
// 	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));
// 	printf("%d\n", printf(" NULL %s NULL ", NULL));
// 	return (0);
// }
