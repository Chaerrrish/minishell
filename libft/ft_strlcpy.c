/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:46:24 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/19 14:50:13 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main(void)
{
	char str1[6] = "Hello";
	char str2[10] = "aaaaaaaaa";
	//char *str3 = "";
	printf("%zu\n", ft_strlcpy(str2, str1, 6));
	printf("%s\n", str2);
	printf("%zu\n", ft_strlcpy(str2, str1, 0));
	return (0);
}*/
