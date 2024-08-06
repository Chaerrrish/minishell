/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:29:52 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 12:41:34 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char *pch;
	char *str = "/|\x12\xff\x09\x42\2002\42|\\";
	pch = (char*)memchr("teste", '\200', 10);
	if (pch != NULL)
		printf("'p' found at position %ld.\n", pch - str + 1);
	else
		printf("'p' not found.\n");
}
*/