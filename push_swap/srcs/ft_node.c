/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:21:32 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/11 12:58:33 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_new_node(long long num)
{
	t_node	*new;

	if (num < -2147483648 || 2147483647 < num)
	{
		print_err();
		return (0);
	}
	new = malloc(sizeof(t_node));
	if (!(new))
		return (0);
	new->num = num;
	new->idx = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*ft_get_node(t_stack *stack)
{
	t_node	*out;

	out = stack->head;
	stack->head = out->next;
	out->prev = out;
	out->next = out;
	stack->size--;
	return (out);
}

void	ft_add_node_back(t_stack *stack, t_node *new)
{
	if (!(stack->head))
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->size += 1;
}

void	ft_add_node_front(t_stack *stack, t_node *new)
{
	if (!(stack->head))
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->head->prev = new;
		new->next = stack->head;
		stack->head = new;
	}
	stack->size += 1;
}
