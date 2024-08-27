/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:15:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/27 19:05:03 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(char **envp)
{
	t_shell	minishell;
	char	*input;
	int		fd_backup[2];

	init_envp_list(&minishell.env_list, envp);
	minishell.cmd_list = NULL;
	while (1)
	{
		fd_backup[0] = dup(STDIN_FILENO);
		fd_backup[1] = dup(STDOUT_FILENO);
		input = readline("tontoshell ༼⍤༽ $ ");
		if (!input)
		{
			printf("exit");
			break;
		}
		if (ft_strlen(input) == 0)
		{
			free(input);
			continue;
		}
		if (parsing(&minishell, input) == -1)
		{
			printf("tontoshell: syntax error: enexpected end of file\n");
			g_status_code = 258;
			free_cmd_list(minishell.cmd_list);
			free(input);
			continue;
		}
		execute(&minishell, envp);
		dup2(fd_backup[0], STDIN_FILENO);
		dup2(fd_backup[1], STDOUT_FILENO);
		add_history(input);
		free(input);
		free_cmd_list(minishell.cmd_list);
	}
	free_env_list(minishell.env_list);
	// system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	term;
	
	(void)argv;
	if (argc >= 2)
	{
		printf("too many arguments!!!\n");
		exit(0);
	}  
	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		perror("tcgetattr error!!!\n");
		exit(0);
	}
	init_signal();
	minishell(envp);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != 0)
	{
		perror("tcsetattr error!!!\n");
		exit(0);
	}
}
