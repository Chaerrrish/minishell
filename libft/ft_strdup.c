/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:42 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 11:47:38 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*dst;
	unsigned char	*src;
	size_t			len_src;
	unsigned int	i;

	i = 0;
	src = (unsigned char *)s1;
	len_src = ft_strlen(s1);
	dst = (char *)malloc(len_src + 1);
	if (!(dst))
		return (0);
	else
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	s1[] = "helloworld!";
	char	*s2 = ft_strdup(s1);

	printf("%s", s2);
}
*/
