/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:05 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:55 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

// 토큰 반복자
typedef struct s_token_iter
{
	int	start;
	int	end;
	int	in_sq;
	int	in_dq;
}	t_token_iter;

// 환경변수(리스트)
typedef struct s_env
{
	char	*data; // 환경 변수가 "PATH=/usr/bin:/bin"이라면, data 필드는 이 전체 문자열
	char	*key; // PATH
	char	*value; // /usr/bin:/bin
}	t_env;

// 토큰 리스트
typedef struct s_token 
{
	char			*str;
	int				type;
	
	struct s_token	*next;
	
}	t_token;

typedef struct s_cmd_list
{	
	t_token				*token_list;	// tokenized list
	
	int					argc;
	char				**argv;
	char				*path;
	int					pipe_cnt;
	int					in_fd;
	int					out_fd;
	char				*heredoc_file;
	int					pipe_fd[2];
	pid_t				pid;
	struct s_cmd_list	*next;			// 다음 cmd_list
		
}	t_cmd_list;

// 종합
typedef struct s_shell
{
	t_list			*env_list;	// 환경변수 리스트
	t_cmd_list		*cmd_list;	// 커맨드 리스트
}	t_shell;

#endif
