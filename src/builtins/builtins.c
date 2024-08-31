/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:10 by chaoh             #+#    #+#             */
/*   Updated: 2024/08/31 14:42:54 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	execute_builtin(t_shell *minishell, t_cmd_list *cmd, char **envp)
{
	redirection(cmd);
	if (cmd->out_fd == STDOUT_FILENO && cmd->in_fd == STDIN_FILENO)
		set_pipe_inout(cmd);
	if (ft_strncmp(cmd->argv[0], "cd", 2) == 0)
		cd(cmd, minishell->env_list);
	else if (!(ft_strncmp(cmd->argv[0], "echo", 4)) \
			|| ft_strncmp(cmd->argv[0], "ECHO", 4) == 0)
		ft_echo(cmd);
	else if (!(ft_strncmp(cmd->argv[0], "env", 3)) \
			|| ft_strncmp(cmd->argv[0], "ENV", 3) == 0)
		env(cmd, minishell->env_list);
	else if (ft_strncmp(cmd->argv[0], "exit", 4) == 0)
		ft_exit(cmd);
	else if (ft_strncmp(cmd->argv[0], "export", 6) == 0)
		export(cmd, minishell->env_list, envp);
	else if (!(ft_strncmp(cmd->argv[0], "pwd", 3)) \
			|| ft_strncmp(cmd->argv[0], "PWD", 3) == 0)
		pwd(cmd);
	else if (ft_strncmp(cmd->argv[0], "unset", 5) == 0)
		unset(cmd, &minishell->env_list);
	else
		return (0);
	return (1);
}
