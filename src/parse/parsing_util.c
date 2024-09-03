/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:07:46 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/02 22:50:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	detach_front(t_token *cur);
static void	detach_back(t_token *cur);

t_token	*detach_redirection(t_token *token_list)
{
	t_token	*cur;
	int		i;

	cur = token_list;
	while (cur)
	{
		if (cur->type != T_WORD)
		{
			cur = cur->next;
			continue ;
		}
		i = 0;
		while (cur->str[i])
		{
			if ((cur->str[i] != '>' && cur->str[i] != '<')
				&& (cur->str[i + 1] == '>' || cur->str[i + 1] == '<'))
				detach_front(cur);
			if ((cur->str[i] == '>' || cur->str[i] == '<')
				&& (cur->str[i + 1] != '>' && cur->str[i + 1] != '<'))
				detach_back(cur);
			i++;
		}
		cur = cur->next;
	}
	return (token_list);
}

static void	detach_front(t_token *cur)
{
	int		i;
	int		end;
	t_token	*new;

	end = 0;
	while (cur->str[end])
		end++;
	i = 0;
	while (cur->str[i] != '<' && cur->str[i] != '>')
		i++;
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		memory_error();
	new->str = ft_strdup(ft_substr(cur->str, i, end - 1));
	new->type = get_token_type(new->str);
	cur->str = ft_substr(cur->str, 0, i);
	cur->type = T_WORD;
	if (cur->next != NULL)
		new->next = cur->next;
	else
		new->next = NULL;
	cur->next = new;
}

static void	detach_back(t_token *cur)
{
	int		i;
	int		end;
	t_token	*new;

	end = 0;
	while (cur->str[end])
		end++;
	i = 0;
	while (cur->str[i] == '>' || cur->str[i] == '<')
		i++;
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		memory_error();
	new->str = ft_strdup(ft_substr(cur->str, i, end));
	new->type = T_WORD;
	cur->str = ft_substr(cur->str, 0, i);
	cur->type = get_token_type(cur->str);
	if (cur->next != NULL)
		new->next = cur->next;
	else
		new->next = NULL;
	cur->next = new;
}

int	is_semi_colon(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ';')
			return (-1);
		i++;
	}
	return (0);
}
