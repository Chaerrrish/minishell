/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:08:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/28 19:53:01 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../header/mini_signal.h"

void	sig_shell(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_status_code = 1;
}

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_status_code = 130;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	set_signal(int s_int, int s_quit)
{
	if (s_int == DEFAULT)
		signal(SIGINT, SIG_DFL);
	if (s_int == IGNORE)
		signal(SIGINT, SIG_IGN);
	if (s_int == SHELL)
		signal(SIGINT, sig_shell);
	if (s_int == HEREDOC)
		signal(SIGINT, sig_heredoc);
	if (s_quit == DEFAULT)
		signal(SIGQUIT, SIG_DFL);
	if (s_quit == IGNORE)
		signal(SIGQUIT, SIG_IGN);
	if (s_quit == SHELL)
		signal(SIGQUIT, SIG_IGN);
}

void	init_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	set_signal(SHELL, SHELL);
}
