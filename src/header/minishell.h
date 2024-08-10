/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/09 22:20:35 by chaoh            ###   ########.fr       */
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

# include "../../Libft/libft.h"
# include "mini_macro.h"
# include "mini_struct.h"
# include "mini_signal.h"

/* env 디렉토리 */
// init_evnp.c
void	init_envp_lst(t_list **lst, char **envp);




/* parse 디렉토리 */
// parsing.c
int	parsing(t_shell *minishell, char *input);



/* signal 디렉토리 */
// signal.c
void	init_signal(void);



/* utils */
// lst_free.c
void	lst_free(t_list *lst);
int		ft_strcmp(const char *s1, const char *s2);
#endif
