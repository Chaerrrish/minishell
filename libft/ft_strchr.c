/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:22:51 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 11:47:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	if ((char)c == 0)
	{
		while (s[i])
			i++;
		return (&s[i]);
	}
	while (s[i] && (char)c)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char str[] = "helloworld";
	char *ptr1 = strchr(str, '\0');
	char *ptr2 = ft_strchr(str, '\0');
	
	printf("%s\n", ptr1);
	printf("%s\n", ptr2);
	}
*/
