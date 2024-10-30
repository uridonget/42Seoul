/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:26:02 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 09:26:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_exit_code(int status, int i)
{
	int	signo;

	if (WIFSIGNALED(status))
	{
		signo = WTERMSIG(status);
		if (signo == SIGINT)
		{
			if (i == 0)
				ft_putstr("\n", 1);
		}
		else if (signo == SIGQUIT)
		{
			if (i == 0)
				ft_putstr("Quit: 3\n", 2);
		}
		return (128 + signo);
	}
	else
		return (WEXITSTATUS(status));
}

t_stage	*get_pid_stage(t_stage *stage, pid_t pid)
{
	while (stage)
	{
		if (stage->pid == pid)
			return (stage);
		stage = stage->next;
	}
	return (NULL);
}

static void	set_dead_process(t_stage *stage, int flag, \
	int status, int *exit_code)
{
	if (stage == 0)
		return ;
	if (stage->prev)
		close(stage->prev->pipe[0]);
	if (stage->next)
		close(stage->pipe[1]);
	if (stage->in_fd != -1)
		close(stage->in_fd);
	if (stage->out_fd != -1)
		close(stage->out_fd);
	if (stage->next == 0)
		*exit_code = get_exit_code(status, flag);
	else
		get_exit_code(status, flag);
}

int	wait_process(t_stage *stage)
{
	int		status;
	pid_t	pid;
	t_stage	*pid_stage;
	int		first_flag;
	int		exit_code;

	first_flag = 0;
	exit_code = -1;
	while (INFINITE)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (pid == -1)
		{
			if (errno == EINTR)
				continue ;
			if (errno == ECHILD)
				break ;
		}
		pid_stage = get_pid_stage(stage, pid);
		set_dead_process(pid_stage, first_flag, status, &exit_code);
		first_flag += 1;
	}
	return (exit_code);
}
