/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:41:30 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/14 12:42:03 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token	*next;                    // 다음 토큰을 가리키는 포인터

	while (tokens)                    // 토큰 리스트를 순회하면서
	{
		next = tokens->next;           // 다음 토큰을 저장
		free(tokens->str);             // 현재 토큰의 문자열을 해제
		free(tokens);                  // 현재 토큰을 해제
		tokens = next;                 // 다음 토큰으로 이동
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (cmd == NULL)
		return ;
	if (cmd->name)
		free(cmd->name);
	if (cmd->path)
		free(cmd->path);
	if (cmd->argv)
	{
		i = 0;
		while (cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
	}
	free(cmd);
}

void	free_ast(t_ASTNode *node)
{
	if (node == NULL)
		return ;
	if (node->left)
		free_ast(node->left);
	if (node->right)
		free_ast(node->right);
	if (node->cmd)
		free_cmd(node->cmd);
	if (node->next)
		free_ast(node->next);
	free(node);
}
