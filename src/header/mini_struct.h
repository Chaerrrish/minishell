/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:05 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:48:16 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

// 커맨드
typedef struct s_command
{
	char	*name;
	char	*path;
	char	**argv;
	int		argc;
}	t_cmd;


// 토큰
typedef struct s_token {
	int				type;
	char			*str;
	struct s_token	*next;
}	t_token;

// 토큰 반복자
typedef struct s_token_iter
{
	int	start;
	int	end;
	int	in_squote;
	int	in_dquote;
}	t_token_iter;

// 커맨드(트리)
typedef struct s_ASTNode
{
	int					type;
	char				*value;
	struct s_ASTNode	*left;
	struct s_ASTNode	*right;
	t_cmd				*cmd; //명령어
	struct s_ASTNode	*next;
	int					pipefd[2];
	pid_t				pid;
	int					status;
}	t_ASTNode;


// 환경변수(리스트)
typedef struct s_env
{
	char	*data; // 환경 변수가 "PATH=/usr/bin:/bin"이라면, data 필드는 이 전체 문자열
	char	*key; // PATH
	char	*value; // /usr/bin:/bin
}	t_env;

// 환경변수(리스트) + 커맨드(트리)
typedef struct s_shell
{
	t_list		*env_list;
	t_ASTNode	*astree_root;
}	t_shell;

#endif
