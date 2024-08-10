/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:31:30 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/10 20:37:33 by wonyocho         ###   ########.fr       */
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
static int	double_qoute_completion(char *input, int index)
{
	while (input[index])
	{
		if (input[index] == '\"')
			return (index + 1); // 짝이 맞는다는 뜻, 그따옴표의 다음위치 인덱스를 리턴.
		index++;
	}
	return (-1); // 끝까지 돌았는데 짝이 안맞으면 -1 리턴
}

static int single_quote_completion(char *input, int index)
{
	while (input[index])
	{
		if (input[index] == '\'')
			return (index + 1); // 짝이 맞는다는 뜻, 따옴표의 다음위치 인덱스를 리턴.
		index++;
	}
	return (-1); // 끝까지 돌았는데 짝이 안맞으면 0 리턴
}

// 짝이 맞으면 1
// 짝이 안맞으면 -1
int	check_quotes(char *input)
{
	int	i;
	int	temp;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\"') // dquote가 짝이 맞는지 확인
		{
			temp = double_qoute_completion(input, i + 1);
			if (temp == 0)
				return (-1);
			i = temp;
		}
		if (input[i] == '\'') // squote가 짝이 맞는지 확인
		{
			temp = single_quote_completion(input, i + 1);
			if (temp == 0)
				return (-1);
			i = temp;
		}
		i++;
	}
	return (1);
}


