/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:31:56 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 12:22:53 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_redirection(t_stage *stage)
{
	if (stage->in_fd == -1)
	{
		if (stage->prev)
			if (dup2(stage->prev->pipe[0], STDIN_FILENO) < 0)
				exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(stage->in_fd, STDIN_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(stage->in_fd);
	}
	if (stage->out_fd == -1)
	{
		if (stage->next)
			if (dup2(stage->pipe[1], STDOUT_FILENO) < 0)
				exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(stage->out_fd, STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(stage->out_fd);
	}
}

static void	ft_execve(t_stage *stage, char **envp)
{
	if (envp == NULL)
		exit(EXIT_FAILURE);
	if (stage->cmd_path)
	{
		if (execve(stage->cmd_path, stage->cmd, envp) < 0)
		{
			ft_putstr("minishell: ", 2);
			ft_putstr(*(stage->cmd), 2);
			perror(" ");
			exit(126);
		}
	}
	else
	{
		ft_putstr("minishell: ", 2);
		ft_putstr(*(stage->cmd), 2);
		ft_putstr(": command not found\n", 2);
		exit(127);
	}
}

void	child_process(t_stage *stage, t_envp **my_envp, char **env_arr)
{
	if (restore_terminal() == 1)
		exit(1);
	set_redirection(stage);
	close_all_pipe(stage);
	init_sig_child();
	if (exec_builtin(stage, my_envp) == 0)
		exit(stage->exit_code);
	if (*(stage->cmd) == 0)
		exit(0);
	ft_execve(stage, env_arr);
}
