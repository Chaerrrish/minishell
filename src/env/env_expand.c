/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:00:19 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 20:59:55 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_to_value(char *result, char *front, char *env_value, char *back)
{
	char	*front_str;
	char	*back_str;

	front_str = front;
	back_str = back;
	while (*front)
		*(result++) = *(front++);
	while (*env_value)
		*(result++) = *(env_value++);
	while (*back)
		*(result++) = *(back++);
	*result = '\0';
	free(front_str);
	free(back_str);
}

static char	*make_expand_data(t_list *env_list, char *str, int start, int end)
{
	int		len;
	char	*key;
	char	*value;
	char	*result;

	key = ft_substr(str, start + 1, end - start);
	if (ft_strcmp(key, "?") == 0)
		value = ft_itoa(g_status_code);
	else
		value = get_env_value(env_list, key);
	len = ft_strlen(str) - (end - start + 1) + ft_strlen(value);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		memory_error();
	change_to_value(result, ft_substr(str, 0, start), value,
		ft_substr(str, end + 1, ft_strlen(str)));
	free(key);
	free(value);
	return (result);
}

char	*expand_env(t_list *env_list, char *token_str)
{
	int		start;
	int		end;
	char	*temp;
	char	*expand_str;

	expand_str = ft_strdup(token_str);
	if (ft_strcmp(expand_str, "$") == 0 && ft_strlen(expand_str) == 1)
		return (expand_str);
	end = 0;
	while (expand_str[end])
		end++;
	if (expand_str[end - 1] == '$')
		return (expand_str);
	start = find_start_pos(expand_str);
	while (start != -1)
	{
		end = find_end_pos(expand_str, start + 1);
		temp = expand_str;
		expand_str = make_expand_data(env_list, expand_str, start, end);
		free(temp);
		start = find_start_pos(expand_str);
	}
	return (expand_str);
}

t_token	*expanded_new_token(char *line, int start, int end)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		memory_error();
	token->str = ft_substr(line, start, end - start);
	if (token->str == NULL)
		memory_error();
	token->type = get_token_type(token->str);
	return (token);
}
