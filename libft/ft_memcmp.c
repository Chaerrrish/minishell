/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:24:45 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/09 14:24:47 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		else
		{
			buf1++;
			buf2++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("memcmp : %d", ft_memcmp("strcmp\0abc", "strcmp\0123", 10));
	printf("strcmp : %d", strncmp("strcmp\0abc", "strcmp\0123", 10));
	return (0);
}*/
