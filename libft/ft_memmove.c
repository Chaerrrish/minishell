/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:35:02 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 16:51:56 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	if ((unsigned char *)dst < (unsigned char *)src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[len - 1 - i]
				= ((unsigned char *)src)[len - 1 - i];
			i++;
		}
	}	
	return ((unsigned char *)dst);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "aaaaa";
	char dst[] = "cc";


	printf("%s\n", ft_memmove(dst, src, 5));
	printf("%s\n", memmove(dst, src, 5));
}
*/
