/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:25:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/24 21:17:30 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_lst_last(t_token *token_lst);

void	process_token(t_shell *mini, t_token **token_lst, char *input,
						t_token_iter *iter)
{
	t_token	*current_token;

	if (iter->end - iter->start > 0)
	{
		current_token = new_token(input, iter->start, iter->end);
		if (!tokenize_expand(mini, token_lst, current_token))
			add_token(token_lst, current_token);
	}
}

t_token	*new_token(char *input, int start, int end)
{
	t_token	*result;

	result = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!result)
		memory_error();
	result->str = ft_substr(input, start, end - start);
	if (!result->str)
		memory_error();
	result->type = get_token_type(result->str);
	if (is_quotation_str(input, start, end))
		result = get_quote_str(result, input, start, end);
	return (result);
}

int	tokenize_expand(t_shell *mini, t_token **token_lst, t_token *token)
{
	t_token	*last_token;
	char	*new_line;

	last_token = token_lst_last(*token_lst);
	if ((last_token && last_token->type == T_REDIR_HERE)
		|| (token->type == T_SINGLE_QUOTE))
		return (0);
	new_line = expand_env(mini->env_list, token->str);
	if (ft_strcmp(token->str, new_line) == 0)
	{
		free(new_line);
		return (0);
	}
	sum_splited_env(token_lst, new_line);
	token_free(token);
	return (1);
}

void	add_token(t_token **token_lst, t_token *token)
{
	t_token	*back;

	if ((*token_lst) == 0)
	{
		*token_lst = token;
		return ;
	}
	back = token_lst_last(*token_lst);
	back->next = token;
}

t_token	*token_lst_last(t_token *token_lst)
{
	if (token_lst == NULL)
		return (NULL);
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	return (token_lst);
}
