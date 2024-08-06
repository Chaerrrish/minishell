/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:13:58 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/19 15:12:40 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char str, char c)
{
	if (str == c)
		return (1);
	else if (str == '\0')
		return (1);
	return (0);
}

static void	word_write(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (check_sep(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

static char	**write_split(char **array, char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (check_sep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep (str[i + j], c) == 0)
				j++;
			array[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!array[word])
				return (free_arr(array));
			word_write(array[word++], str + i, c);
			i = i + j;
		}
	}
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		word;
	char	*a;
	int		i;

	i = 0;
	word = 0;
	a = (char *)s;
	while (a[i])
	{
		if (check_sep(a[i + 1], c) == 1 && (check_sep(a[i], c)) == 0)
			word++;
		i++;
	}
	array = (char **)malloc(sizeof(char *) * (word + 1));
	if (!(array))
		return (0);
	array[word] = 0;
	array = write_split(array, a, c);
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char **a;

	a = ft_split("\0aaaa\0bbb", '\0');
	while (*a)
	{
		printf("%s\n", *a);
		a++;
	}
}
*/