/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:55 by chaerin           #+#    #+#             */
/*   Updated: 2024/08/17 00:03:57 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str != NULL)
	{
		printf("%s\n", str);
	}
	else
		perror("pwd");
	free(str);
}
