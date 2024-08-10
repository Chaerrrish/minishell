/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:18:52 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/09 22:20:10 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
