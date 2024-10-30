/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:26:37 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 16:59:11 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	size_t	i;
	t_node	*temp;
	t_node	*next;

	if (!(stack))
		return ;
	temp = stack->head;
	i = 0;
	while (i < stack->size)
	{
		next = temp->next;
		free(temp);
		temp = next;
		i++;
	}
	free(stack);
}

void	free_all(t_vars *vars)
{
	free_stack(vars->a);
	free_stack(vars->b);
	free(vars);
	exit(1);
}
