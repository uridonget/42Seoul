/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:36:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 14:13:44 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_vars *vars)
{
	size_t	min;

	min = 0;
	while (vars->a->size != 0)
	{
		if (vars->a->head->idx <= min)
		{
			ft_command(vars, "pb", 1);
			min++;
		}
		else if ((min < vars->a->head->idx) && \
		(vars->a->head->idx <= min + vars->chunk))
		{
			ft_command(vars, "pb", 1);
			ft_command(vars, "rb", 1);
			min++;
		}
		else
		{
			if (min < (vars->a->size / 2))
				ft_command(vars, "rra", 1);
			else
				ft_command(vars, "ra", 1);
		}
	}
}
