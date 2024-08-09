/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:31 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:38:15 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

static char	*ft_strddup(char const *s, int len, int pos)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((sizeof(char) * len) + 1);
	if (ptr == NULL)
		return (0);
	while (i < len)
	{
		ptr[i] = s[pos];
		i++;
		pos++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**do_split(char const *s, char c, char **arr, int pos)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	while (++j < count_size(s, c))
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		pos = i;
		while (s[i] != c && s[i++] != '\0')
			len++;
		arr[j] = ft_strddup(s, len, pos);
		if (arr[j] == 0)
		{
			arr = free_arr(arr);
			return (0);
		}
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		pos;

	pos = 0;
	arr = NULL;
	if (count_size(s, c) == 0 && c == '\0')
	{
		arr = (char **)malloc(sizeof(char *) * 1);
		if (arr == NULL)
			return (0);
		arr[0] = NULL;
		return (arr);
	}
	arr = (char **)malloc(sizeof(char *) * (count_size(s, c) + 1));
	if (arr == NULL)
	{
		free (arr);
		return (0);
	}
	arr = do_split(s, c, arr, pos);
	return (arr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[2] = "a";

// 	int i = 0;
// 	printf("size : %d\n", count_size("hello!", ' '));
// 	char **rt = ft_split("hello!", ' ');
// 	while (i < count_size("hello!", ' '))
// 	{
// 		printf("%s\n", rt[i]);
// 		i++;
// 	}
// 	// char **expected = ft_split("\0aa\0bbb", '\0');

//  	// for (int i = 0; expected[i]; i++)
//  	// {
//  	// 	if (expected[i] != ((void *)0))
//  	// 		printf("fail");
// 	// 		return(0);
//  	// }
// 	// printf("success");
// 	return (0);
// }