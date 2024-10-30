/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:28:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/24 11:45:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_init(t_vars *vars, int ac, char *av[], char *envp[])
{
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		if (ac < 6)
			fail_exit("Error number of argument");
		vars->flag = 1;
		vars->limiter = av[2];
		vars->cmd_num = ac - 4;
	}
	else
	{
		if (ac < 5)
			fail_exit("Error number of argument");
		vars->flag = 0;
		vars->limiter = NULL;
		vars->cmd_num = ac - 3;
	}
	open_file(vars, ac, av);
	set_path(vars, av, envp);
}
