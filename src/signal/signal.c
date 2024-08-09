/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:08:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/09 15:00:24 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 터미널을 종료시키는 인터럽트를 발생시켰을 때
// 터미널이 종료되는게 아니라 우리의 minishell만
// 종료되도록 액션을 변경해줘야 한다.

// ctrl + c = SIGINT
// 실행을 중지하고 프로세스를 종료시킨다.
// ctrl + '\' = SIGQUIT
// 실행을 중지하고 코어 덤프.
// 코어 덤프는 프로그램이 비정상적으로 종료되었을 때 작성중이던 메모리 상태를 기록한 파일이다.
// ctrl + d
// 프로세스를 정상종료시킴.
// standard input에 EOF를 등록한다. 쉘에 더이상 명령을 입력하지 않겠다는 뜻.
// 즉, 프로세스 할일을 모두 마치고 터미널 종료시킴.

#include "minishell.h"

// SIGINT 신호를 처리하는 함수 (사용자가 Ctrl+C를 눌렀을 때)
void sig_shell(int sig)
{
    // 새로운 줄을 출력하여 프롬프트가 새로운 줄에서 시작되도록 함
    printf("\n");
    // Readline 라이브러리를 사용하여 새로운 줄을 표시
    rl_on_new_line();
    // 현재 줄을 빈 문자열로 대체
    rl_replace_line("", 0);
    // 변경된 내용을 디스플레이
    rl_redisplay();
    // 전역 상태 코드를 1로 설정
    g_status_code = 1;
}

// SIGINT 신호를 처리하는 함수 (heredoc 처리 중 사용자가 Ctrl+C를 눌렀을 때)
void sig_heredoc(int sig)
{
    // Readline 라이브러리를 사용하여 새로운 줄을 표시
    rl_on_new_line();
    // 현재 줄을 빈 문자열로 대체
    rl_replace_line("", 0);
    // 변경된 내용을 디스플레이
    rl_redisplay();
    // 새로운 줄을 출력
    printf("\n");
    // 프로그램을 종료 (상태 코드 1)
    exit(1);
}

// 신호 처리를 설정하는 함수
void set_signal(int s_int, int s_quit)
{
    // SIGINT 신호에 대한 처리를 설정
    if (s_int == DEFAULT)
        signal(SIGINT, SIG_DFL);   // 기본 동작으로 설정
    if (s_int == IGNORE)
        signal(SIGINT, SIG_IGN);   // 무시로 설정
    if (s_int == SHELL)
        signal(SIGINT, sig_shell); // sig_shell 함수로 설정
    if (s_int == HEREDOC)
        signal(SIGINT, sig_heredoc); // sig_heredoc 함수로 설정
    
    // SIGQUIT 신호에 대한 처리를 설정
    if (s_quit == DEFAULT)
        signal(SIGQUIT, SIG_DFL);   // 기본 동작으로 설정
    if (s_quit == IGNORE)
        signal(SIGQUIT, SIG_IGN);   // 무시로 설정
    if (s_quit == SHELL)
        signal(SIGQUIT, SIG_IGN);   // 쉘에서 무시로 설정
}

// 시그널 초기화를 설정하는 함수
void init_signal(void)
{
    struct termios term;

    // 현재 터미널 속성을 가져옴
    tcgetattr(STDIN_FILENO, &term);
    // ECHOCTL 플래그를 비활성화 (Ctrl + C 등의 제어 문자가 표시되지 않도록 함)
    term.c_lflag &= ~(ECHOCTL);
    // 변경된 터미널 속성을 즉시 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    // 시그널 처리를 쉘 모드로 설정
    set_signal(SHELL, SHELL);
}
