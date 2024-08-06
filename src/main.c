/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:15:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/06 20:46:44 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell()
{
	t_cmd	*cmd;
	char	*input;
	
	cmd = create_new_cmd();
	if (!cmd)
		return ;
	while (1)
	{
		input = readline("minishell $ ");
		if (!input)
			break;
		tokenize(cmd, input);
		/*
			이부분에 실행부로 패스하는 함수 제작
		*/ 
		add_history(input);
		cmd->next = create_new_cmd();
		if (cmd->next == NULL)
		{
			// todo: 이부분에 에러 처리 함수 만들기 (전부 다 free 해주는 함수 만들기)
			break;
		}
		cmd = cmd->next;
		free(input);
	}
}

int	main(int argc, char **argv)
{
	struct termios	term;
	
	if (argc >= 2)
	{
		printf("too many arguments!!!\n");
		exit(0);
	}  
	if (tcgetattr(STDIN_FILENO, &term) != 0) // 터미널 속성 저장
	{
		perror("tcgetattr error!!!");
		exit(0);
	}
	init_signal(); // 시그널 초기화
	minishell(); // 미니쉘 실행
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != 0) // 터미널 속성 복원
	{
		perror("tcsetattr error!!!");
		exit(0);
	}
}
