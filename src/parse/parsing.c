/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:17:24 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parsing(t_shell *mini, char *input)
{
	t_token	*token_lst; // 토큰 리스트의 헤드 포인터
	int		result; // 함수 결과를 저장할 변수

	token_lst = NULL; // 토큰 리스트 초기화
	result = tokenize(mini, &token_lst, input); // 입력 문자열을 토큰화하여 토큰 리스트 생성
	if (result != 0) // 토큰화에 실패한 경우
		return (result); // 에러 코드를 반환
	result = astree(mini, token_lst); // 토큰 리스트를 AST(추상 구문 트리)로 변환
	if (result != 0) // AST 변환에 실패한 경우 
		return (result); // 에러 코드를 반환
	return (0); // 성공적으로 파싱을 완료한 경우 0을 반환
}
