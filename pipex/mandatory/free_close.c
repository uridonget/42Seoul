/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:22:20 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fail_exit(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void	free_double(char **dou)
{
	int	i;

	i = 0;
	if (!(dou))
		return ;
	while (dou[i])
	{
		free(dou[i]);
		i++;
	}
	free(dou);
}

void	free_triple(char ***tri)
{
	int	i;

	i = 0;
	if (!(tri))
		return ;
	while (tri[i])
	{
		free_double(tri[i]);
		i++;
	}
	free(tri);
}

void	close_fd(t_vars *vars)
{
	close(vars->infile);
	close(vars->outfile);
}

void	free_close(t_vars *vars)
{
	close_fd(vars);
	free_triple(vars->cmd);
	free_double(vars->cmd_path);
}
