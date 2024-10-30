/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:40:22 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:10:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_file(t_vars *vars, int ac, char *av[])
{
	vars->infile = open(av[1], O_RDONLY);
	if (vars->infile == -1)
		fail_exit("Error opening infile");
	vars->outfile = open(av[ac - 1], \
	O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars->outfile == -1)
	{
		close(vars->infile);
		fail_exit("Error opening outfile");
	}
}
