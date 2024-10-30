/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:54:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/11 12:57:50 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_left(t_stack *stack)
{
	size_t	i;
	size_t	j;
	t_node	*chk;
	t_node	*temp;

	i = 0;
	temp = stack->head;
	while (i < stack->size)
	{
		j = 0;
		chk = stack->head;
		while (j < i)
		{
			if (chk->num < temp->num)
				temp->idx += 1;
			if (chk->num == temp->num)
				return (0);
			chk = chk->next;
			j++;
		}
		temp = temp->next;
		i++;
	}
	return (1);
}

static void	ft_right(t_stack *stack)
{
	size_t	i;
	size_t	j;
	t_node	*chk;
	t_node	*temp;

	i = 0;
	temp = stack->tail;
	while (i < stack->size)
	{
		j = 0;
		chk = stack->tail;
		while (j < i)
		{
			if (chk->num < temp->num)
				temp->idx += 1;
			chk = chk->prev;
			j++;
		}
		temp = temp->prev;
		i++;
	}
}

int	set_idx(t_stack *stack)
{
	if (!(ft_left(stack)))
		return (print_err());
	ft_right(stack);
	return (1);
}
