/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:02:59 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 10:18:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	size_t			i;
	size_t			j;

	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(arr))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = (unsigned char)s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i] = (unsigned char)s2[j];
		i++;
		j++;
	}
	arr[i] = 0;
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	char s1[] = "";
	char s2[] = "world";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/