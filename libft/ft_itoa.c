/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:37:10 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/02 13:08:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(int n)
{
	int	count;

	count = 0;
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

static char	*get_arr(char *arr, int n, int count)
{
	if (n < 0)
		arr = (char *)malloc(sizeof(char) * count + 2);
	else
		arr = (char *)malloc(sizeof(char) * count + 1);
	return (arr);
}

static char	*put_arr(char *arr, int n, int count)
{
	int	i;
	int	num;

	num = n;
	i = 0;
	if (n == -2147483648)
	{
		arr[i++] = '8';
		num = num / 10;
		num = -num;
		count--;
	}
	else if (n < 0)
		num = -n;
	while (count > 0)
	{
		arr[i++] = num % 10 + '0';
		num /= 10;
		count--;
	}
	if (n < 0)
		arr[i++] = '-';
	arr[i] = '\0';
	return (arr);
}

static char	*swap_arr(char *arr, int count)
{
	int		i;
	char	temp;
	int		time;

	i = 0;
	time = count / 2;
	while (time > 0)
	{
		temp = arr[count - 1 - i];
		arr[count - 1 - i] = arr[i];
		arr[i] = temp;
		i++;
		time--;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		count;

	arr = NULL;
	count = count_n(n);
	arr = get_arr(arr, n, count);
	if (!arr)
		return (NULL);
	arr = put_arr(arr, n, count);
	if (n < 0)
		count++;
	arr = swap_arr(arr, count);
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	int	n = -2147483648;
	
	printf("자릿수: %d\n", count_n(n));
	printf("결과: %s\n", ft_itoa(n));
}
*/