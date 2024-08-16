/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 18:43:54 by wonyocho         ###   ########.fr       */
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

# include "../../libft/libft.h"
# include "mini_macro.h"
# include "mini_struct.h"
# include "mini_signal.h"




/* builtins */
//export.c, export_utils.c
void	swap_content(t_list *a, t_list *b);
void	sort_export_list(t_list *export_list);
t_env	*copy_env(t_env *env);
t_list	*copy_env_list(t_list *env_list);
void	show_env(t_list *env_list, char *input);
int	    check_builtin_argv(char	*str);
//env.c










/*   ---------------- parsing ----------------*/

// env_init.c
void	init_envp_lst(t_list **lst, char **envp);
// env_expand.c
char	*expand_env(t_list *env_list, char *origin);
// env_util.c
t_env	*find_by_key(t_list *env_list, char *target_key);
int		is_valid(char *s, int i);
int		find_start_pos(char *s);
int		find_end_pos(char *s, int i);
char	*get_env_value(t_list *env_list, char *key);



// parsing.c
int	parsing(t_shell *minishell, char *input);
int	add_cmd_list(t_shell *minishell, t_list *current_token_list);



// tokenize.c
int			tokenize(t_shell *minishell, t_token **token_lst, char *input);
// tokenize_process.c
void		process_quotes(const char c, t_token_iter *iter);
void		process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter);
t_token		*new_token(char *line, int l, int r);
int			tokenize_expand(t_shell *mini, t_token **token_lst, t_token *token);
void		add_token(t_token **token_lst, t_token *token);
// tokenize_remove.c
void		remove_quotes(t_token *token_lst);
// tokenize_util1.c
void		token_free(t_token *token);
void		token_lst_free(t_token *token_lst);
t_token		*token_lst_back(t_token *token_lst);
t_token		*expanded_new_token(char *line, int l, int r);
// tokenize_util2.c
int			is_whitespace(const char c);
void		skip_whitespace(const char *input, t_token_iter *iter);
int			is_quotation_str(char *str, int l, int r);
int			check_token_type(char c);
int			get_token_type(const char *str);





// signal.c
void	init_signal(void);

// lst_free.c
void	lst_free(t_list *lst);
void	split_free(char **str);
int		ft_strcmp(const char *s1, const char *s2);
void	memory_error(void);


#endif
