/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:43:57 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:24:21 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*put_zero(void)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 2);
	if (arr == NULL)
		return (0);
	arr[0] = '0';
	arr[1] = '\0';
	return (arr);
}

static char	*put_arr(char *arr, int size, int idx, long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
		arr[size] = '\0';
		size -= 1;
	}
	else
		arr[size] = '\0';
	while (i < size)
	{
		arr[idx] = n % 10 + '0';
		n /= 10;
		idx--;
		i++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*arr;
	int			idx;
	long long	ln;

	ln = (long long)n;
	if (ln == 0)
		return (put_zero());
	size = count_size(ln);
	arr = (char *)malloc((sizeof(char) * size) + 1);
	if (arr == NULL)
		return (0);
	idx = size - 1;
	arr = put_arr(arr, size, idx, ln);
	return (arr);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}*/
