/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:56 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 14:26:36 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	get_chunk(t_stack *a)
{
	double	size;
	double	chunk;

	size = (double)a->size;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	return ((size_t)chunk);
}

void	push_swap(t_vars *vars)
{	
	if (is_sorted(vars->a))
		return ;
	if (vars->a->size <= 3)
		sort_a(vars);
	else if (vars->a->size <= 6)
	{
		while (vars->a->size != 3)
			ft_command(vars, "pb", 1);
		sort_6(vars);
	}
	else
	{
		vars->chunk = get_chunk(vars->a);
		a_to_b(vars);
		b_to_a(vars, vars->b->size - 1);
	}
}
