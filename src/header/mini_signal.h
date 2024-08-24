/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:27:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/24 19:14:44 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SIGNAL_H
# define MINI_SIGNAL_H

# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>

# define DEFAULT 11
# define IGNORE 12
# define SHELL 13
# define HEREDOC 14

int	g_status_code;
void	sig_shell(int sig);
void	sig_heredoc(int sig);
void	set_signal(int s_int, int s_quit);
void	init_signal(void);

#endif