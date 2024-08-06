/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:15:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/06 13:15:45 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "macro.h"

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		printf("too many arguments!\n");
		exit(0);
	}
	
	// 1. 터미널설정 초기화
	// 2. 시그널 초기화
	minishell(); // 3. 미니쉘 실행부분

	return (0);
}
