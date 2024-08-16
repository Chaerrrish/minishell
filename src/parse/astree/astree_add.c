/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:06:45 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/16 14:09:20 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set)
{
	t_ASTNode	*arg_node;
	t_ASTNode	*current_arg;

	arg_node = add_node(T_ARG, token->str);
	if (command_node->right == NULL)
		command_node->right = arg_node;
	else
	{
		current_arg = command_node->right;
		while (current_arg->next)
			current_arg = current_arg->next;
		current_arg->next = arg_node;
	}
	if (!(*cmd_set))
	{
		command_node->value = token->str; // 이건 왜 또 하는거?
		*cmd_set = 1;
	}
	return (0);
}

int	add_redirection(t_ASTNode *command_node, t_token **token)
{
	t_ASTNode	*redir_node;

	if ((*token)->next == NULL)
		return (1);
	redir_node = add_node((*token)->type, (*token)->next->str);
	*token = (*token)->next;
	redir_node->left = command_node->left;
	command_node->left = redir_node;
	return (0);
}

t_ASTNode	*add_node(int type, char *value)
{
	t_ASTNode	*node;

	node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
	node->type = type;
	node->value = value;
	return (node);
}
