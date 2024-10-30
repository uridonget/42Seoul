/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:28:22 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:35:44 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	wait_process(t_vars *vars)
{
	int		cnt;
	int		status;

	cnt = 0;
	while (cnt < vars->cmd_num)
	{
		if (wait(&status) == -1)
		{
			free_close(vars);
			fail_exit("Error wait");
		}
		cnt++;
	}
}

static void	pipex(t_vars *vars, char *envp[])
{
	int	i;

	i = -1;
	if (dup2(vars->infile, STDIN_FILENO) == -1)
	{
		free_close(vars);
		fail_exit("Error dup");
	}
	while (++i < vars->cmd_num)
		exec_cmd(vars, i, envp);
	wait_process(vars);
	free_close(vars);
}

int	main(int ac, char *av[], char *envp[])
{
	t_vars	vars;

	ft_init(&vars, ac, av, envp);
	pipex(&vars, envp);
	return (0);
}
