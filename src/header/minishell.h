/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 13:18:45 by wonyocho         ###   ########.fr       */
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
# include "mini_macro.h"
# include "mini_struct.h"
# include "mini_signal.h"




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






// astree.c
int			astree(t_shell *minishell, t_token *tokens);

// astree_add.c
int			add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set);
int			add_redirection(t_ASTNode *command_node, t_token **token);
t_ASTNode	*add_node(int type, char *value);

// astree_free.c
void		free_tokens(t_token *tokens);
void		free_cmd(t_cmd *cmd);
void		free_ast(t_ASTNode *node);

// astree_util.c
void		new_cmd(t_ASTNode *node);
int			is_redirect(t_token *token);






// tokenize.c
int			tokenize(t_shell *minishell, t_token **token_lst, char *input);

// tokenize_process.c
int			process_quotes(const char c, t_token_iter *iter);
void		process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter);
t_token		*new_token(char *line, int l, int r);
int			tokenize_expand(t_shell *mini, t_token **token_lst, t_token *token);
void		add_token(t_token **token_lst, t_token *token);

// tokenize_remove.c
void		remove_quotes(t_token *token_lst);

// tokenize_util1.c
void		token_free(t_token *token);
void		token_lst_free(t_token **token_lst);
t_token		*token_lst_back(t_token *token_lst);
t_token		*expanded_new_token(char *line, int l, int r);

// tokenize_util2.c
int			is_whitespace(const char c);
void		skip_whitespace(const char *input, t_token_iter *iter);
int			is_quotation_str(char *str, int l, int r);
int			check_token_type(char c);
int			get_token_type(const char *str);


/* signal 디렉토리 */
// signal.c
void	init_signal(void);



/* utils */
// lst_free.c
void	lst_free(t_list *lst);
int		ft_strcmp(const char *s1, const char *s2);
void	memory_error(void);


#endif
