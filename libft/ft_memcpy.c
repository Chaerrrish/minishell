/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:34:19 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/18 12:15:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	if (!(src) && !(dst))
		return (NULL);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char src[] = "";
	char dst[] = "";

	//memcpy(dst, src, 5);
	ft_memcpy((void *)0, (void *)0, 3);
	printf("%s", dst);
}
*/
