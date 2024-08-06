/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:28:54 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/18 12:10:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	start = 0;
	end = ft_strlen(s1);
	if (*s1)
	{
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!(str))
			return (0);
		else
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	else
	{
		str = ft_strdup("");
		return (str);
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_strtrim("", "cdef"));
}
*/