/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:29:31 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:17:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	make_tree(t_shell *minishell, t_token **current_token);
static int	parse_command(t_ASTNode **node, t_token **current_token);

int	astree(t_shell *minishell, t_token *tokens)
{
	t_token	*current_token;           // 현재 처리 중인 토큰을 가리키는 포인터
	int		result;                   // 파싱 결과를 저장할 변수

	current_token = tokens;            // current_token을 토큰 리스트의 시작으로 초기화
	result = make_tree(minishell, &current_token); // 첫 번째 토큰부터 파이프라인을 파싱
	if (result != 0)
		return (result);
	return (0);                        // 파싱이 성공하면 0을 반환
}

static int	make_tree(t_shell *minishell, t_token **current_token)
{
	t_ASTNode	*pipe_node;            // 파이프 노드를 가리키는 포인터
	t_ASTNode	*left_command;         // 왼쪽 명령어 노드를 가리키는 포인터
	int			result;                // 파싱 결과를 저장할 변수

	result = parse_command(&left_command, current_token); // 첫 번째 명령어를 파싱
	if (result != 0)
		return (result);
	while (*current_token && (*current_token)->type == T_PIPE) // 현재 토큰이 파이프이면 반복
	{
		pipe_node = add_node(T_PIPE, NULL); // 파이프 노드를 생성
		pipe_node->left = left_command;        // 왼쪽 노드에 이전 명령어를 연결
		*current_token = (*current_token)->next; // 다음 토큰으로 이동
		result = parse_command(&pipe_node->right, current_token); // 오른쪽 명령어를 파싱
		if (result != 0)                    // 파싱에 실패하면 오류 코드를 반환
			return (result);
		left_command = pipe_node;           // 파이프 노드를 새로운 왼쪽 명령어로 설정
	}
	minishell->astree_root = left_command;       // 최종 파싱된 명령어 트리를 minishell 구조체에 저장
	return (0);                             // 성공적으로 완료하면 0을 반환
}

static int	parse_command(t_ASTNode **node, t_token **current_token)
{
	t_ASTNode	*command_node;       // 새로운 명령어 노드를 가리키는 포인터
	int			cmd_set;             // 명령어가 설정되었는지 확인하는 플래그
	int			result;              // 파싱 결과를 저장할 변수

	command_node = add_node(T_CMD, NULL); // 명령어 노드를 생성하고 초기화
	cmd_set = 0;                             // 명령어가 설정되지 않았음을 의미하는 0으로 초기화
	while (*current_token && (*current_token)->type != T_PIPE) // 파이프 토큰이 나올 때까지 반복
	{
		if (is_redirect(*current_token))    // 현재 토큰이 리다이렉션인지 확인
			result = add_redirection(command_node, current_token); // 리다이렉션을 명령어 노드에 추가
		else
			result = add_argument(command_node, *current_token, &cmd_set); // 그렇지 않으면 명령어에 인자를 추가
		if (result != 0)
			return (result);
		*current_token = (*current_token)->next; // 다음 토큰으로 이동
	}
	new_cmd(command_node);                 // 새 명령어를 설정
	*node = command_node;                  // 명령어 노드를 반환
	return (0);                            // 성공적으로 완료하면 0을 반환
}
