/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:25:24 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 16:45:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	pa(t_vars *vars)
{
	if (vars->b->size == 0)
		return (1);
	ft_add_node_front(vars->a, ft_get_node(vars->b));
	return (1);
}

int	pb(t_vars *vars)
{
	if (vars->a->size == 0)
		return (1);
	ft_add_node_front(vars->b, ft_get_node(vars->a));
	return (1);
}
