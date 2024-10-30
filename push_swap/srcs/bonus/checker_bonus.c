/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:40:25 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/15 16:52:15 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	ft_loop(t_vars *vars)
{
	char	*cmd;

	(void)vars;
	while (1)
	{
		cmd = get_next_line(0);
		if (!(cmd))
			break ;
		else if (!(ft_command(vars, cmd, 0)))
		{
			write(2, "Error\n", 6);
			free_all(vars);
		}
		free(cmd);
	}
	if ((is_sorted(vars->a)) && (vars->b->size == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		i;
	t_vars	*vars;

	if (ac == 1)
		return (0);
	vars = malloc(sizeof(t_vars));
	if (!(vars))
		return (0);
	if (!(init_stack(vars)))
		free_all(vars);
	i = 1;
	while (i < ac)
		if (!(insert_num(av[i++], vars->a)))
			free_all(vars);
	if (!(set_idx(vars->a)))
		free_all(vars);
	ft_loop(vars);
	free_stack(vars->a);
	free_stack(vars->b);
	free(vars);
	exit(0);
	return (0);
}
