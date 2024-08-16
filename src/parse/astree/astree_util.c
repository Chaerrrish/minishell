/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:42:53 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:05:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_argc(t_ASTNode *node)
{
	size_t	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

static char	**concat_args(t_ASTNode *node, int len)
{
	char		**result;
	t_ASTNode	*tmp_node;
	int			i;

	tmp_node = node;
	result = (char **)ft_calloc(len + 1, sizeof(char *));
	tmp_node = node;
	i = 0;
	while (i < len)
	{
		result[i] = ft_strdup(tmp_node->value);
		tmp_node = tmp_node->next;
		i++;
	}
	return (result);
}

void	new_cmd(t_ASTNode *node)
{
	node->cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	node->cmd->name = node->value;
	node->cmd->argc = get_argc(node->right);
	node->cmd->argv = concat_args(node->right, node->cmd->argc);
}

int	is_redirect(t_token *token)
{
	return (token->type == T_REDIR_IN || token->type == T_REDIR_OUT
		|| token->type == T_REDIR_APPEND || token->type == T_REDIR_HERE
		|| token->type == T_REDIR_ERR);
}

