/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:24 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/12 15:08:28 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	size_t	i;
	t_node	*temp;
	t_node	*next;

	i = 0;
	temp = stack->head;
	while (i < stack->size - 1)
	{
		next = temp->next;
		if (temp->idx > next->idx)
			return (0);
		temp = next;
		i++;
	}
	return (1);
}
