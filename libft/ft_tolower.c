/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:18:20 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/19 21:36:00 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main ()
{
	int c = -1;
	printf("%d\n", tolower(c));
	printf("%d\n", ft_tolower(c));
}
*/