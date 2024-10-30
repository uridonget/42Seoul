/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:27:47 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:19 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = ft_get_node(stack);
	second = ft_get_node(stack);
	ft_add_node_front(stack, first);
	ft_add_node_front(stack, second);
}

int	sa(t_stack *a)
{
	if (a->size < 2)
		return (1);
	ft_swap(a);
	return (1);
}

int	sb(t_stack *b)
{
	if (b->size < 2)
		return (1);
	ft_swap(b);
	return (1);
}

int	ss(t_vars *vars)
{
	if (vars->a->size > 1)
		ft_swap(vars->a);
	if (vars->b->size > 1)
		ft_swap(vars->b);
	return (1);
}
