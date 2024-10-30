/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:20:59 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/12 12:37:05 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!(new))
		return (0);
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

int	init_stack(t_vars *vars)
{
	vars->a = ft_new_stack();
	vars->b = ft_new_stack();
	if ((!(vars->a)) || (!(vars->b)))
		return (0);
	return (1);
}
