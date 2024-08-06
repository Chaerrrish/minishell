/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:13:08 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/21 13:08:10 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{
	int a = 'a';
	printf("%d", toupper(a));
	//printf("%d", ft_toupper(a));
}
*/
