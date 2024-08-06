/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:02:47 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:21 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = ft_strlen(s);
	if (!(str) || !(char)c)
		return (&s[i]);
	i--;
	while (i > -1)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "xteste";
	char *ptr = ft_strrchr(str, 'x');
	printf("%c, %s", *ptr, ptr);
}
*/