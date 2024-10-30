/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:57:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	close_exit(t_vars *vars, int fd[2], char *msg, int n)
{
	if (n == 1)
	{
		close(fd[0]);
		close(fd[1]);
	}
	free_close(vars);
	fail_exit(msg);
}

static void	redirection(int fd[2], int pid, t_vars *vars)
{
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
		{
			close(fd[1]);
			free_close(vars);
			fail_exit("Error dup2");
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			close(fd[0]);
			free_close(vars);
			fail_exit("Error dup2");
		}
		close(fd[0]);
	}
}

static void	not_last_cmd(t_vars *vars, int i, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		free_close(vars);
		fail_exit("Error making pipe");
	}
	pid = fork();
	if (pid == -1)
		close_exit(vars, fd, "Error fork", 1);
	if (pid == 0)
	{
		redirection(fd, pid, vars);
		if (execve(vars->cmd_path[i], vars->cmd[i], envp) == -1)
			close_exit(vars, fd, "Error execute", 1);
	}
	else
		redirection(fd, pid, vars);
}

static void	last_cmd(t_vars *vars, int i, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		free_close(vars);
		fail_exit("Error fork");
	}
	if (pid == 0)
	{
		if (dup2(vars->outfile, STDOUT_FILENO) == -1)
		{
			free_close(vars);
			fail_exit("Error dup");
		}
		if (execve(vars->cmd_path[i], vars->cmd[i], envp) == -1)
		{
			free_close(vars);
			fail_exit("Error execute");
		}
	}
	else
		close(STDIN_FILENO);
}

void	exec_cmd(t_vars *vars, int i, char *envp[])
{
	if (i < vars->cmd_num - 1)
		not_last_cmd(vars, i, envp);
	else
		last_cmd(vars, i, envp);
}
