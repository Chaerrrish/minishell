/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:05 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/06 19:50:14 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cmd
{
	char	**cmd_line; // cmdline[0] = "echo", cmdline[1] = "hi", cmdline[2] = NULL
	int		pipe_flag; // flag 0: 세미콜론 또는 NULL, flag 1: 파이프
	int		single_quote; // 파싱과정에서 ' 또는 " 를 저장, 짝을 찾으면 0으로 초기화 됨.
	int				double_quote;
	struct s_cmd	*next; 
}t_cmd;

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}t_env;

#endif