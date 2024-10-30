/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:28:28 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 10:56:39 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	chk_builtin(t_stage *stage)
{
	char	*cmd;

	if (stage->cmd == 0 || *(stage->cmd) == 0)
		return (-1);
	cmd = *(stage->cmd);
	if (ft_strcmp(cmd, "echo") == 0)
		return (E_ECHO);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (PWD);
	else if (ft_strcmp(cmd, "export") == 0)
		return (EXPORT);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (UNSET);
	else if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (EXIT);
	return (-1);
}

static void	run_builtin(t_stage *stage, t_envp **my_envp, int builtin_code)
{
	if (builtin_code == E_ECHO)
		stage->exit_code = echo_builtin(stage->cmd);
	else if (builtin_code == CD)
		stage->exit_code = cd_builtin(*my_envp, (stage->cmd)[1]);
	else if (builtin_code == PWD)
		stage->exit_code = pwd_builtin();
	else if (builtin_code == EXPORT)
		stage->exit_code = export_builtin(*my_envp, stage->cmd);
	else if (builtin_code == UNSET)
		stage->exit_code = unset_builtin(my_envp, stage);
	else if (builtin_code == ENV)
		stage->exit_code = env_builtin(*my_envp, stage);
	else
		exit_builtin(stage);
}

int	exec_builtin(t_stage *stage, t_envp **my_envp)
{
	int		builtin_code;

	builtin_code = chk_builtin(stage);
	if (builtin_code == -1)
	{
		return (1);
	}
	run_builtin(stage, my_envp, builtin_code);
	return (0);
}
