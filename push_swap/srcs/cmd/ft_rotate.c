/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:30:05 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/15 16:50:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_node	*temp;

	temp = ft_get_node(stack);
	ft_add_node_back(stack, temp);
}

int	ra(t_stack *a)
{
	if (a->size < 2)
		return (1);
	ft_rotate(a);
	return (1);
}

int	rb(t_stack *b)
{
	if (b->size < 2)
		return (1);
	ft_rotate(b);
	return (1);
}

int	rr(t_vars *vars)
{
	if (vars->a->size > 1)
		ft_rotate(vars->a);
	if (vars->b->size > 1)
		ft_rotate(vars->b);
	return (1);
}
