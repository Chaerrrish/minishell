/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:43 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 12:57:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
	char s2[] = "\xff\0\0\xaa\0\xde\x00MBS";
	int n = 8;
	int a = ft_memcmp(s1, s2, n);
	int b = memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", a);
	printf("memcmp: %d\n", b);
}
*/