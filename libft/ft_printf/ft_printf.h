/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:44:18 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:21:35 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n, int fd, int cnt);
int	ft_putunbr(unsigned int n, int cnt);
int	print_hex_up(va_list ap, int cnt);
int	print_hex_low(va_list ap, int cnt);
int	get_address(va_list ap, int cnt);
int	print_char(va_list ap, int cnt);
int	print_str(va_list ap, int cnt);
int	print_dec(va_list ap, int cnt);
int	print_unsigned(va_list ap, int cnt);

#endif
