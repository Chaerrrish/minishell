/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:55 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/07 16:50:50 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str != NULL)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	else
		perror("pwd");
	free(str);
}
