/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:49:52 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/06 18:49:54 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(unsigned char *dst, unsigned char *src, int i, int len)
{
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = src[i];
		if (i == 0)
			break ;
		i--;
	}
}

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (dst < src)
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		reverse(dst, src, i, len);
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char arr[5] = "abcd";
	printf("%s\n", ft_memmove(arr+1, arr, 2));
	return (0);
}*/