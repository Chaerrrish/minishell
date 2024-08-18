/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:00:19 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/18 19:33:19 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_to_value(char *result, char *front, char *env_value, char *back)
{
	int		i;
	char	*front_str;
	char	*back_str;

	front_str = front;
	back_str = back;
	i = 0;
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

static char	*make_expand_data(t_list *env_list, char *origin, int start, int end)
{
	int		len;
	char	*key;
	char	*value;
	char	*result;

	key = ft_substr(origin, start + 1, end - start);
	printf("key: %s\n", key);
	if (ft_strcmp(key, "?") == 0)
		value = ft_itoa(g_status_code);
	else
		value = get_env_value(env_list, key);
	len = ft_strlen(origin) - (end - start + 1) + ft_strlen(value);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		memory_error();
	change_to_value(result, ft_substr(origin, 0, start),
		value, ft_substr(origin, end + 1, ft_strlen(origin)));
	free(key);
	free(value);
	return (result);
}

char	*expand_env(t_list *env_list, char *str) // $ 으로 시작
{
	int		start;
	int		end;
	char	*temp;
	char	*expand_str;

	expand_str = ft_strdup(str);
	printf("expand str: %s\n", expand_str);
	start = find_start_pos(expand_str);
	printf("start: %d\n", start);
	while (start != -1)
	{
		end = find_end_pos(expand_str, start + 1);
		printf("end: %d\n", end);
		temp = expand_str;
		expand_str = make_expand_data(env_list, expand_str, start, end);
		printf("new_expand str: %s\n", expand_str);
		free(temp);
		start = find_start_pos(expand_str);
	}
	return (expand_str);
}
