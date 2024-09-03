/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/03 13:57:02 by wonyocho         ###   ########.fr       */
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
int		execute_builtin(t_shell *minishell, t_cmd_list *cmd, char **envp);
void	pwd(t_cmd_list *cmd);
void	cd(t_cmd_list *list, t_list *env_list);
void	ft_echo(t_cmd_list *list);
void	env(t_cmd_list *list, t_list *env_list);
t_list	*copy_env_list(t_list *env_list);
t_env	*copy_env(t_env *env);
void	sort_env_list(t_list *export_list);
void	swap_content(t_list *a, t_list *b);
void	export(t_cmd_list *list, t_list *env_list, char **envp);
void	print_export_list(t_cmd_list *list, t_list *env_list);
void	ft_exit(t_cmd_list *list);
void	unset(t_cmd_list *list, t_list **env_list);

//check_argv.c
int	    check_export_argv(char	*str);
int 	check_unset_argv(char *str);
int		check_exit_argv(t_cmd_list *cmd);


/* execute */
//set_path.c
void	set_cmd_path(t_cmd_list *list, t_list *env_list);

//execute.c
void	execute(t_shell	*shell, char **envp);
void	make_process(t_cmd_list *cmd, t_shell *shell);
void	execute_exec(t_cmd_list *cmd, t_shell *shell, char **envp);
void	child_process(t_cmd_list *cmd, t_shell *shell, char **new_envp);
void	parent_process(t_cmd_list *cmd);
void	change_inout(t_cmd_list *cmd);

//execute_utils.c
int		get_status(void);
void	set_pipe_inout(t_cmd_list *cmd);
void	unlink_heredoc_files(t_shell *shell);
char	*make_tmp_file(void);

//heredoc.c
int		heredoc(t_cmd_list *list, t_shell *shell);
void	heredoc_main(int fd, char *delimeter);
int		check_heredoc(t_cmd_list *list, t_token *token, t_shell *shell);
void	execute_heredoc(char *delimeter, t_cmd_list *cmd, t_shell *shell);
int		create_heredoc_file(t_shell *shell, char **filename);

//redir.c
void	redirection(t_cmd_list *cmd);
void	set_redir_inout(t_cmd_list *cmd);
void	redir_in(t_cmd_list *cmd, t_token *token);
void	redir_out(t_cmd_list *cmd, t_token *token);
t_token	*get_last_redir(t_token *token);

/*   -------------------------------- parsing --------------------------------------*/

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
void	change_to_value(char *result, char *front, char *env_value, char *back);


// create_cmd_list.c
t_cmd_list	*create_cmd_list(t_token *token_list);
t_cmd_list	*init_cmd_node(void);
// get_cmd_data.c
void 	get_cmd_data(t_token **current, t_token *total, t_cmd_list *cmd);
void	get_argc(t_cmd_list *cmd_list, t_token *lst, t_token *total);
char	**get_argv(t_token *token_list, int size);
void	get_pipe_data(t_cmd_list **cmd_list, t_token **current_token);


// parsing.c
int		parsing(t_shell *minishell, char *input);
int 	add_cmd_list(t_shell *minishell, t_token *token_list);
// parsing_util.c
t_token *detach_redirection(t_token *token_list);
int		is_back_redir(t_token *result, int end);
void 	detach(t_token *result, int end);
int		is_semi_colon(char *input);


// get_token_type.c
int		get_token_type(const char *str);
int		is_builtin(const char *str);
// process_quotes.c
void	process_quotes(char *input, t_token_iter *iter);
// process_token_util.c
t_token	*get_str(t_token *result, char *input, int start, int end);
void	sum_splited_env(t_token **token_lst, char *new_line);
// process_token.c
void	get_token(t_shell *mini, t_token **token_lst, char *input, t_token_iter *iter);
t_token	*make_token(char *input, t_token_iter *iter);
int		expand_token_env(t_shell *mini, t_token **token_lst, t_token *token);
void	add_to_last_token(t_token **token_lst, t_token *token);
// remove_quotes.c
void	remove_quotes(t_token *token_lst);
void	do_remove(t_token *token);
// tokenize_util.c
int		check_token_type(char c);
void	skip_whitespace(const char *input, t_token_iter *iter);
int		is_quote(char *str, int start, int end);
int		is_redirection(const char *input, t_token_iter *iter);
int		is_whitespace(const char c);
// tokenize.c
int		tokenize(t_shell *minishell, t_token **token_lst, char *input);





// signal
// signal.c
void	init_signal(void);




// utils
void	free_env_list(t_list *lst);
void	free_cmd_list(t_cmd_list *cmd_list);
void	free_token_list(t_token *token_list);
void	free_env(void *content);
char	**list_to_array(t_list *list);
int		only_whitespace(char *input);
void	split_free(char **str);
int		ft_strcmp(const char *s1, const char *s2);
void	memory_error(void);
void	print_cmd_error(char *str);
int check_redir_in_a_row(char *input);


#endif 
