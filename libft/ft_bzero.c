/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:21:51 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 15:27:38 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>
int main()
{
	char str1[] = "helloworldwonyocho";
	char str2[] = "helloworldwonyocho";
	int i = 0;
	ft_bzero(str1, 3);
	bzero(str2, 3);
	while (str1[i])
	{
		printf("ft_bzero: %s\n", &str1[i]);
		i++;
	}
	printf("bzero: %s\n", str2);
}
*/
