/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:13:57 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/18 14:40:08 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	arr = (char *)malloc(len + 1);
	if (!(arr))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			arr[j] = s[i];
			j++;
		}
		i++;
	}
	arr[j] = '\0';
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	char *s = "tripouille";
	printf("ft_substr: %s\n", ft_substr(s, 0, 42000));
}
*/