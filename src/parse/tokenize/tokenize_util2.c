/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:16 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/14 15:50:29 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(const char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

void	skip_whitespace(const char *input, t_token_iter *iter)
{
	while (input[iter->end] && is_whitespace(input[iter->end]))
		iter->end++;
}

int	is_quotation_str(char *str, int l, int r)
{
	if (str[l] == '\'' && str[r - 1] == '\'')
		return (1);
	if (str[l] == '\"' && str[r - 1] == '\"')
		return (1);
	return (0);
}

// token 타입을 확인하는 함수
int	check_token_type(char c)
{
	if (c == '\'') // 문자가 싱글 쿼터라면
		return (T_SINGLE_QUOTE); // 싱글 쿼터 타입 반환
	else
		return (T_DOUBLE_QUOTE); // 더블 쿼터 타입 반환
}

int	get_token_type(const char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (T_PIPE);
	else if (ft_strcmp(str, "<") == 0)
		return (T_REDIR_IN);
	else if (ft_strcmp(str, ">") == 0)
		return (T_REDIR_OUT);
	else if (ft_strcmp(str, "<<") == 0)
		return (T_REDIR_HERE);
	else if (ft_strcmp(str, ">>") == 0)
		return (T_REDIR_APPEND);
	else if (ft_strcmp(str, "2>") == 0)
		return (T_REDIR_ERR);
	else
		return (T_WORD);
}
