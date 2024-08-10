/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:38:57 by wonyocho         ###   ########.fr       */
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





/* parse 디렉토리 */
// quote.c
int	process_quotes(const char c, t_token_iter *iter);
int	check_quotes(char *input);
// tokenize_util.c
void	process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter);
// tokenize.c
int	tokenize(t_shell *minishell, t_token *token_lst, char *input);
// whitespace.c
int	is_whitespace(const char c);
void	skip_whitespace(const char *input, t_token_iter *iter);





/* utils */
// lst_free.c
void	lst_free(t_list *lst);
int		ft_strcmp(const char *s1, const char *s2);
#endif
