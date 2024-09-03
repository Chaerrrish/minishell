/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:25:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/03 13:55:49 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_list_last(t_token *token_list);

void	get_token(t_shell *mini, t_token **token_list, char *input,
						t_token_iter *iter)
{
	t_token	*current_token;
	int		expand_flag;

	expand_flag = 0;
	if (iter->end - iter->start > 0)
	{
		current_token = make_token(input, iter);
		expand_flag = expand_token_env(mini, token_list, current_token);
		if (expand_flag == 0)
			add_to_last_token(token_list, current_token);
	}
}

t_token	*make_token(char *input, t_token_iter *iter)
{
	t_token	*result;

	result = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!result)
		memory_error();
	result->str = ft_substr(input, iter->start, iter->end - iter->start);
	if (!result->str)
		memory_error();
	result->type = get_token_type(result->str);
	if (is_quote(input, iter->start, iter->end))
		result = get_str(result, input, iter->start, iter->end);
	return (result);
}

int	expand_token_env(t_shell *mini, t_token **token_list, t_token *token)
{
	t_token	*last_token;
	char	*new_line;

	last_token = token_list_last(*token_list);
	if ((last_token && last_token->type == T_REDIR_HERE)
		|| (token->type == T_SINGLE_QUOTE))
		return (0);
	new_line = expand_env(mini->env_list, token->str);
	if (ft_strcmp(token->str, new_line) == 0)
	{
		free(new_line);
		return (0);
	}
	sum_splited_env(token_list, new_line);
	token_free(token);
	free(new_line);
	return (1);
}

void	add_to_last_token(t_token **token_list, t_token *token)
{
	t_token	*back;

	if ((*token_list) == 0)
	{
		*token_list = token;
		return ;
	}
	back = token_list_last(*token_list);
	back->next = token;
}

t_token	*token_list_last(t_token *token_list)
{
	if (token_list == NULL)
		return (NULL);
	while (token_list->next != NULL)
		token_list = token_list->next;
	return (token_list);
}
