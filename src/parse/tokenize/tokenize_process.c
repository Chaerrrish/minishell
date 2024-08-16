/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:25:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:11:50 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_quotes(const char c, t_token_iter *iter)
{
	if (c == '\'' && !iter->in_dquote) // 현재 문자가 싱글 쿼터이고 더블 쿼터 내에 있지 않다면
		iter->in_squote = !iter->in_squote; // 싱글 쿼터 상태 토글
	else if (c == '"' && !iter->in_squote) // 현재 문자가 더블 쿼터이고 싱글 쿼터 내에 있지 않다면
		iter->in_dquote = !iter->in_dquote; // 더블 쿼터 상태 토글
	return (0);
}

// 토큰을 생성하고 리스트에 추가함
void	process_token(t_shell *mini, t_token **token_lst, char *line, t_token_iter *iter)
{
	t_token	*token;

	if (iter->end > iter->start) // 토큰의 길이가 0보다 크다면
	{
		token = new_token(line, iter->start, iter->end); // 새로운 토큰 생성
		if (!tokenize_expand(mini, token_lst, token)) // 토큰 확장에 실패하면
			add_token(token_lst, token); // 토큰 리스트에 추가
	}
}

// 새로운 token을 생성하는 함수
t_token	*new_token(char *line, int l, int r)
{
	t_token	*token;
	char	*tmp;

	token = (t_token *)ft_calloc(1, sizeof(t_token)); // 새로운 token 할당 및 초기화
	if (token == NULL) // 메모리 할당 실패 시
		memory_error(); // 메모리 오류 처리 함수 호출
	token->str = ft_substr(line, l, r - l); // 입력 문자열에서 토큰 문자열 추출
	if (token->str == NULL) // 문자열 추출 실패 시
		memory_error(); // 메모리 오류 처리 함수 호출
	token->type = get_token_type(token->str); // 토큰 타입 설정
	if (is_quotation_str(line, l, r)) // 문자열이 인용부호로 감싸져 있는지 확인
	{
		token->type = check_token_type(line[l]); // 인용부호 타입 설정
		tmp = token->str; // 기존 문자열 임시 저장
		if (l + 1 == r) // 인용부호만 있는 경우
			token->str = ft_calloc(0, sizeof(char)); // 빈 문자열 할당
		else
			token->str = ft_substr(line, l + 1, r - l - 2); // 인용부호를 제외한 문자열 추출
		if (token->str == NULL) // 문자열 추출 실패 시
			memory_error(); // 메모리 오류 처리 함수 호출
		free(tmp); // 기존 문자열 메모리 해제
	}
	return (token); // 새로운 토큰 반환
}

int	tokenize_expand(t_shell *mini, t_token **token_lst, t_token *token)
{
	t_token	*back;
	char	*new_line;
	char	**splited;
	t_token	*token_tmp;
	int		i;

	back = token_lst_back(*token_lst);
	if (back && back->type == T_REDIR_HERE || token->type == T_SINGLE_QUOTE)
		return (0);
	new_line = expand_env(mini->env_list, token->str);
	if (ft_strcmp(token->str, new_line) == 0)
	{
		free(new_line);
		return (0);
	}
	splited = ft_split(new_line, ' ');
	i = 0;
	while (splited[i])
	{
		token_tmp = expanded_new_token(splited[i], 0, ft_strlen(splited[i]));
		add_token(token_lst, token_tmp);
		i++;
	}
	token_free(token);
	return (1);
}

// token 리스트에 새로운 token을 추가하는 함수
void	add_token(t_token **token_lst, t_token *token)
{
	t_token	*back;

	if ((*token_lst) == 0) // token 리스트가 비어있다면
	{
		*token_lst = token; // 첫 번째 요소로 새로운 token 설정
		return ;
	}
	back = token_lst_back(*token_lst); // 리스트의 마지막 요소를 찾음
	back->next = token; // 마지막 요소의 다음에 새로운 token 연결
}


