/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_stages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:56 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 16:46:04 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_last_code(t_stage *stage)
{
	int	res;

	res = 258;
	while (stage != 0 && stage->next != 0)
		stage = stage->next;
	if (stage != 0)
		res = stage->exit_code;
	return (res);
}

static int	get_exit_code(int status)
{
	if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == 2)
			return (1);
		return (128 + status);
	}
	else
		return (WEXITSTATUS(status));
}

static int	wait_heredoc(t_stage *stage)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 0;
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
		process_heredoc(stage);
	else
	{
		while (waitpid(pid, &status, WUNTRACED) == -1)
		{
			if (errno == EINTR)
				continue ;
			else
				break ;
		}
		status = get_exit_code(status);
		if (status == 2)
			exit(2);
	}
	return (status);
}

static void	run_stage(t_stage *stage, t_envp **my_envp, int exit_code)
{
	while (stage)
	{
		stage->exit_code = exit_code;
		if (*(stage->cmd))
			stage->cmd_path = get_path(*my_envp, stage->cmd);
		if (exec_cmd(stage, my_envp))
		{
			stage = stage->next;
			continue ;
		}
		stage = stage->next;
	}
}

int	run_stages(t_stage *stage, t_envp **my_envp, int exit_code)
{
	int		res_code;

	check_heredoc_number(stage);
	name_tmpfile(stage);
	res_code = wait_heredoc(stage);
	if (res_code != 0)
	{
		write(1, "\n", 1);
		free_stages(stage);
		return (res_code);
	}
	res_code = -1;
	run_stage(stage, my_envp, exit_code);
	res_code = wait_process(stage);
	if (res_code == -1)
		res_code = get_last_code(stage);
	free_stages(stage);
	return (res_code);
}
