/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:05 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/29 17:45:57 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

typedef struct s_token_iter
{
	int	start;
	int	end;
	int	in_sq;
	int	in_dq;
}	t_token_iter;

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_token 
{
	char			*str;
	int				type;
	
	struct s_token	*next;
	
}	t_token;

typedef struct s_cmd_list
{	
	t_token				*token_list;
	
	int					argc;
	char				**argv;
	char				*path;
	int					pipe_cnt;
	int					in_fd;
	int					out_fd;
	char				*heredoc_file;
	int					pipe_fd[2];
	pid_t				pid;
	struct s_cmd_list	*next;
		
}	t_cmd_list;

typedef struct s_shell
{
	t_list			*env_list;
	t_cmd_list		*cmd_list;
	int				pipe_flag;
	char			*heredoc_files[100];
	int				heredoc_cnt;
}	t_shell;

#endif
