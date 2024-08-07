/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/07 16:16:38 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <curses.h>

# include "libft.h"
# include "macro.h"
# include "struct.h"


// parsing.c
t_cmd	*create_new_cmd();
void	tokenize(t_cmd *cmd, char *str);

// check_quotes.c
int		check_single_quotes(char *str);
int		check_double_quotes(char *str);

// signal.c
void	init_signal();

#endif













// void	exec_proc(t_list *head) // 인자는 연결리스트의 헤드포인터
// {
// 	t_list	*cur_proc;
// 	t_cmd	*cmd;

// 	cur_proc = head->next;
// 	while (cur_proc != NULL)
// 	{
// 		cmd = cur_proc->content; // 각 노드의 content는 data->cmd의 주소를 갖는다.
// 		if (cmd->cmdline[0]) // 명령어가 있으면 실행
// 		{
// 			if (cmd->flag == 1)
// 			 	exec_pipe(cur_proc, cmd);
//       else if (cmd->flag == 0)
// 				exec_cmd(cmd->cmdline); // 인자는 cur_proc->content->cmdline
// 		}
// 		cur_proc = cur_proc->next; // 다음 노드로 이동
// 	}
// 	ft_lstclear(&head, free_cmdline); // 연결리스트 비워줌
// }