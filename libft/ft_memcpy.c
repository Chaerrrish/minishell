/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:44:21 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/19 14:49:45 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorc;

	i = 0;
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char arr[2] = "\0";
	char dest[2];
	//printf("%s\n", ft_memcpy((void *)0, "segfaulter tu dois", 17));
	printf("%s\n", memcpy((void *)0, "segfaulter tu dois", 17));
	return (0);
}*/
