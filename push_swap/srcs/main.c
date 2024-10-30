/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:13:15 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 16:49:39 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	push_swap(vars);
	free_stack(vars->a);
	free_stack(vars->b);
	free(vars);
	exit(0);
	return (0);
}
