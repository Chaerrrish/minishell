/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:47:14 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:23:28 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	count_size(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (check(set, s1[i]) == 0)
	{
		len--;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (check(set, s1[i]) == 0)
	{
		len--;
		i--;
	}
	if (len <= 0)
		return (0);
	return (len);
}

static char	*do_trim(char const *s1, char const *set, char *str, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check(set, s1[i]) == 0)
		i++;
	while (j < size)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	char	*s;

	s = (char *)s1;
	if ((s == NULL) && (set == NULL))
		return (0);
	size = count_size(s, set);
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (str == NULL)
		return (0);
	str = do_trim(s, set, str, size);
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *s1 = "  \t \t \n   \n\nhello\tworld\t";
// 	//char	*s1 = "\t\t\the\n  llo\n";
// 	char set[] = "xyz";

// 	printf("%s\n", ft_strtrim("", ""));
// 	//printf("%s\n", ft_strtrim(s1, ""));
// }
