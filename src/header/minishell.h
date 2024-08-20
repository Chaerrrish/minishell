/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/20 19:29:19 by chaoh            ###   ########.fr       */
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
# include <fcntl.h>

# include "../../libft/libft.h"
# include "mini_macro.h"
# include "mini_struct.h"
# include "mini_signal.h"




/* builtins */
int		execute_builtin(t_shell *minishell);
void	pwd(void);
void	cd(t_cmd_list *list, t_list *env_list);
void	ft_echo(t_cmd_list *list, t_list *env_list);
void	env(t_cmd_list *list, t_list *env_list);
t_list	*copy_env_list(t_list *env_list);
t_env	*copy_env(t_env *env);
void	sort_export_list(t_list *export_list);
void	swap_content(t_list *a, t_list *b);
void	export(t_cmd_list *list, t_list *env_list);
void	print_export_list(t_list *env_list);
int	    check_builtin_argv(char	*str);
void	ft_exit(t_cmd_list *list, t_list *env_list);
void	unset(t_cmd_list *list, t_list **env_list);


void	heredoc(t_cmd_list *list);
void	heredoc_parent(int fd, char *delimeter);
void	check_heredoc(t_cmd_list *list, t_token *token);
void	execute_heredoc(char *delimeter, t_cmd_list *cmd);

/* execute */
//set_path.c
void	set_cmd_path(t_cmd_list *list, t_list *env_list);

//execute.c
void	execute(t_shell	*shell);
void	execute_cmd(t_cmd_list *cmd, t_shell *shell);
void	execute_child(t_cmd_list *cmd, t_shell *shell, char  **envp);

/*   ---------------- parsing ----------------*/

// env_init.c
void	init_envp_list(t_list **lst, char **envp);
// env_util.c
t_env	*find_by_key(t_list *env_list, char *target_key);
int		is_valid(char *s, int i);
int		find_start_pos(char *s);
int		find_end_pos(char *s, int i);
char	*get_env_value(t_list *env_list, char *key);
t_token	*expanded_new_token(char *line, int l, int r);
char	*expand_env(t_list *env_list, char *origin);
void	token_free(t_token *token);
void	sum_splited_env(t_token **token_lst, char *new_line);




// parsing.c
int	parsing(t_shell *minishell, char *input);
int add_cmd_list(t_shell *minishell, t_token *token_list);



// tokenize.c
int			tokenize(t_shell *minishell, t_token **token_lst, char *input);
// tokenize_process.c
void		process_quotes(char *input, t_token_iter *iter);
void		process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter);
t_token		*new_token(char *line, int l, int r);
int	tokenize_expand(t_shell *mini, t_token **token_lst, t_token *token);
void		add_token(t_token **token_lst, t_token *token);
// tokenize_remove.c
void		remove_quotes(t_token *token_lst);
// tokenize_util.c
t_token		*token_lst_last(t_token *token_lst);
int			is_whitespace(const char c);
int	is_quotation_str(char *str, int start, int end);
int			check_token_type(char c);
int			get_token_type(const char *str);
int 		is_builtin(const char *str);
t_token	*get_quote_str(t_token *result, char *input, int start, int end);



// cmd_list
t_cmd_list	*create_cmd_list(t_token *token_list);
t_cmd_list	*new_cmd_node(t_token *start_token, int argc);
void		add_cmd_node(t_cmd_list **cmd_list, t_cmd_list *new_cmd);
t_token		*recreate_token(char **argv, int argc);






// signal.c
void	init_signal(void);


// utils
void	tonto_is_free(t_shell *minishell);
void	free_env_list(t_list *lst);
void	free_cmd_list(t_cmd_list *cmd_list);
void	free_token_list(t_token *token_list);
void	free_env(void *content);

char	**list_to_array(t_list *list);

void	split_free(char **str);
int		ft_strcmp(const char *s1, const char *s2);
void	memory_error(void);
void	print_cmd_error(char *str);

#endif 
