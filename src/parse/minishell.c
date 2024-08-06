/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/06 13:15:02 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*create_new_cmd()
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd_line = NULL;
	new_cmd->pipe_flag = 0;
	new_cmd->single_quote = 0;
	new_cmd->double_quote = 0;
	new_cmd->next = NULL;
	return (new_cmd);
}

static void	loop(t_cmd *cmd)
{
	char	*str;
	
	while (1)
	{
		str = readline("minishell $ ");
		if (!str)
		 	break;
		if (*str != '\0')
		{
			cmd->single_quote = check_single_quotes(str); // 매크로: 짝이 안맞음
			cmd->double_quote = check_double_quotes(str); // 매크로: 짝이 안맞음
			cmd->cmd_line = ft_split(str, ' '); // 띄어쓰기 기준으로 스플릿
			if (ft_strchr(str, '|')) // pipe 존재하면 1
				cmd->pipe_flag = 1;
			else
				cmd->pipe_flag = 0;
			add_history(str); 
			cmd->next = create_new_cmd();
			if (cmd->next == NULL)
			 	break;
		}
		free(str);
	}
} 

void	minishell()
{
	t_cmd	*cmd;
	
	cmd = create_new_cmd();
	if (!cmd)
		return ;
	loop(cmd);
	
	/*
		실행부
	*/
}





// 스플릿 확인하는 부분
// printf("str:%s\nsq:%d dq:%d\n", str, cmd->single_quote, cmd->double_quote);
// int i = 0;
// while (cmd->cmd_line[i])
// {
// 	printf("%s\n", cmd->cmd_line[i]);
// 	i++;
// }
