/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:07:32 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/12 16:14:17 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a_2(t_vars *vars)
{
	t_node	*f;
	t_node	*s;

	f = vars->a->head;
	s = f->next;
	if (s->idx < f->idx)
		ft_command(vars, "sa", 1);
}

void	sort_a(t_vars *vars)
{
	t_node	*f;
	t_node	*s;

	f = vars->a->head;
	s = f->next;
	if (vars->a->size == 2)
		sort_a_2(vars);
	else if ((s->idx < f->idx) && (f->idx < s->next->idx))
		ft_command(vars, "sa", 1);
	else if ((s->next->idx < s->idx) && (s->idx < f->idx))
	{
		ft_command(vars, "sa", 1);
		ft_command(vars, "rra", 1);
	}
	else if ((s->next->idx < f->idx) && (f->idx < s->idx))
		ft_command(vars, "rra", 1);
	else if ((f->idx < s->next->idx) && (s->next->idx < s->idx))
	{
		ft_command(vars, "sa", 1);
		ft_command(vars, "ra", 1);
	}
	else if ((s->idx < s->next->idx) && (s->next->idx < f->idx))
		ft_command(vars, "ra", 1);
}

static void	sort_b_2(t_vars *vars)
{
	t_node	*f;
	t_node	*s;

	f = vars->b->head;
	s = f->next;
	if (s->idx > f->idx)
		ft_command(vars, "sb", 1);
}

void	sort_b(t_vars *vars)
{
	t_node	*f;
	t_node	*s;

	f = vars->b->head;
	s = f->next;
	if (vars->b->size == 2)
		sort_b_2(vars);
	else if ((s->idx > f->idx) && (f->idx > s->next->idx))
		ft_command(vars, "sb", 1);
	else if ((s->next->idx > s->idx) && (s->idx > f->idx))
	{
		ft_command(vars, "sb", 1);
		ft_command(vars, "rrb", 1);
	}
	else if ((s->next->idx > f->idx) && (f->idx > s->idx))
		ft_command(vars, "rrb", 1);
	else if ((f->idx > s->next->idx) && (s->next->idx > s->idx))
	{
		ft_command(vars, "sb", 1);
		ft_command(vars, "rb", 1);
	}
	else if ((s->idx > s->next->idx) && (s->next->idx > f->idx))
		ft_command(vars, "rb", 1);
}

void	sort_6(t_vars *vars)
{
	size_t	size_a;
	size_t	size_b;

	size_a = vars->a->size;
	size_b = vars->b->size;
	sort_a(vars);
	sort_b(vars);
	while (size_a + size_b != 0)
	{
		if (size_b == 0 || ((size_a > 0) && \
		(vars->a->tail->idx > vars->b->head->idx)))
		{
			ft_command(vars, "rra", 1);
			size_a--;
		}
		else
		{
			ft_command(vars, "pa", 1);
			size_b--;
		}
	}
}
