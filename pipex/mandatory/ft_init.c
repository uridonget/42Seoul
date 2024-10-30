/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:28:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:10:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init(t_vars *vars, int ac, char *av[], char *envp[])
{
	if (ac != 5)
		fail_exit("Error number of argument");
	vars->cmd_num = ac - 3;
	open_file(vars, ac, av);
	set_path(vars, av, envp);
}
