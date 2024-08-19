/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:15:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/19 13:57:01 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(char **envp)
{
	t_shell	minishell;
	char	*input;
	int		fd_backup[2];

	init_envp_list(&minishell.env_list, envp);	// 환경변수 리스트 초기화
	minishell.cmd_list = NULL;			// cmd 리스트 초기화
	while (1)
	{
		fd_backup[0] = dup(STDIN_FILENO);	// 표준 입력 백업
		fd_backup[1] = dup(STDOUT_FILENO);	// 표준 출력 백업
		input = readline("tontoshell🌝 $ ");
		if (!input) // EOF(Ctrl + D) or readline 오류시 에러핸들링
			break;
		if (parsing(&minishell, input) == -1) // parsing 에러시 -1
		{
			perror("parsing error\n");
			free(input);
			continue;
		}
		// 명령어 경로 설정
		if (minishell.cmd_list->token_list->type == T_BULTIN)
			execute_builtin(&minishell);
		dup2(fd_backup[0], STDIN_FILENO);	// 백업
		dup2(fd_backup[1], STDOUT_FILENO);	// 백업 
		add_history(input);
		free(input);
		minishell.cmd_list = minishell.cmd_list->next;
	}
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
	if (tcgetattr(STDIN_FILENO, &term) != 0) // 터미널 속성 저장
	{
		perror("tcgetattr error!!!\n");
		exit(0);
	}
	init_signal(); // 시그널 초기화
	minishell(envp); // 미니쉘 실행
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != 0) // 터미널 속성 복원
	{
		perror("tcsetattr error!!!\n");
		exit(0);
	}
}
