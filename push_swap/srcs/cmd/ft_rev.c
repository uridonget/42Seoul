/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:35:07 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/15 16:50:28 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_rev(t_stack *stack)
{
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail = stack->tail->prev;
	stack->head = stack->head->prev;
	stack->head->prev = stack->head;
}

int	rra(t_stack *a)
{
	if (a->size < 2)
		return (1);
	ft_rev(a);
	return (1);
}

int	rrb(t_stack *b)
{
	if (b->size < 2)
		return (1);
	ft_rev(b);
	return (1);
}

int	rrr(t_vars *vars)
{
	if (vars->a->size > 1)
		ft_rev(vars->a);
	if (vars->b->size > 1)
		ft_rev(vars->b);
	return (1);
}
