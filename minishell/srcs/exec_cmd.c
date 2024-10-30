/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:17:22 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 14:47:32 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	std_temp(t_stage *stage, int flag)
{
	if (flag == 0)
	{
		stage->stdin_temp = dup(STDIN_FILENO);
		if (stage->stdin_temp == -1)
			exit(EXIT_FAILURE);
		stage->stdout_temp = dup(STDOUT_FILENO);
		if (stage->stdout_temp == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(stage->stdin_temp, STDIN_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(stage->stdin_temp);
		if (dup2(stage->stdout_temp, STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(stage->stdout_temp);
	}
}

static void	exec_stage(t_stage *stage, t_envp **my_envp, char **env_arr)
{
	pid_t	pid;

	if ((stage->prev == NULL) && (stage->next == NULL) && \
		(chk_builtin(stage) != -1))
	{
		std_temp(stage, 0);
		set_redirection(stage);
		exec_builtin(stage, my_envp);
		close_all_pipe(stage);
		std_temp(stage, 1);
		return ;
	}
	if (stage->next == NULL)
		close_pipe(stage);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	stage->pid = pid;
	if (pid == 0)
		child_process(stage, my_envp, env_arr);
}

int	exec_cmd(t_stage *stage, t_envp **my_envp)
{
	char	**env_arr;

	if (open_file(stage))
	{
		if (stage->prev)
			close(stage->prev->pipe[0]);
		close(stage->pipe[1]);
		stage->exit_code = 1;
		return (1);
	}
	env_arr = list_to_envp(*my_envp);
	exec_stage(stage, my_envp, env_arr);
	free_strs(env_arr);
	return (0);
}
