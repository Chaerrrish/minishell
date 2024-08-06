/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:30 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:49:43 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (len > 0)
	{
		str[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char str[] = "helloworldwonyocho";

	printf("%s\n", memset(str, '\0', 5));
	printf("%s\n", ft_memset(str, '\0', 5));
}
*/
