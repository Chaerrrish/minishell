/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:10 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/25 19:27:49 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	execute_builtin(t_shell *minishell, t_cmd_list *cmd, char **envp)
{
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		cd(cmd, minishell->env_list);
	else if (!(ft_strcmp(cmd->argv[0], "echo")) \
				|| ft_strcmp(cmd->argv[0], "ECHO") == 0)
		ft_echo(cmd);
	else if (!(ft_strcmp(cmd->argv[0], "env")) \
				|| ft_strcmp(cmd->argv[0], "ENV") == 0)
		env(cmd, minishell->env_list);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		ft_exit(cmd);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		export(cmd, minishell->env_list, envp);
	else if (!(ft_strcmp(cmd->argv[0], "pwd")) \
				|| ft_strcmp(cmd->argv[0], "PWD") == 0)
		pwd(cmd);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		unset(cmd, &minishell->env_list);
	else
		return (0);
	return (1);
}
