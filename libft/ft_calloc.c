/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:11 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 21:02:56 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mal;
	char			*arr;
	unsigned int	i;

	mal = (void *)malloc(size * count);
	if (!(mal))
		return (NULL);
	arr = (char *)mal;
	i = 0;
	while (i < size * count)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	char	*arr0;
	char	*arr1;

	arr0 = calloc(5, 4);
	arr1 = ft_calloc(5, 4);
	for (int i = 0; i < 20; i++)
		printf("%d: %s |%d: %s\n", i, arr0, i, arr1);
}
*/
