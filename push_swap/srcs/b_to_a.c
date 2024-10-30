/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:41:15 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/13 14:26:37 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_b_di(size_t target, t_vars *vars)
{
	t_node	*find_b_top;
	t_node	*find_b_bot;

	if (vars->a->size != 0 && vars->a->tail->idx == target)
		return (0);
	find_b_top = vars->b->head->next;
	find_b_bot = vars->b->tail;
	while (1)
	{
		if (find_b_top->idx == target)
			return (1);
		else if (find_b_bot->idx == target)
			return (2);
		else
		{
			find_b_top = find_b_top->next;
			find_b_bot = find_b_bot->prev;
		}
	}
}

static void	rotate_b(int di, int *bot, t_vars *vars, size_t *target)
{
	if (di == 0)
	{
		ft_command(vars, "rra", 1);
		(*target)--;
		(*bot)--;
	}
	if (di == 1)
		ft_command(vars, "rb", 1);
	else if (di == 2)
		ft_command(vars, "rrb", 1);
}

void	b_to_a(t_vars *vars, size_t target)
{
	int		bot;

	bot = 0;
	while (vars->b->size != 0)
	{
		if (vars->b->head->idx == target)
		{
			ft_command(vars, "pa", 1);
			target--;
		}
		else if (bot == 0 || vars->b->head->idx > vars->a->tail->idx)
		{
			ft_command(vars, "pa", 1);
			ft_command(vars, "ra", 1);
			bot++;
		}
		else
			rotate_b(find_b_di(target, vars), &bot, vars, &target);
	}
	while (bot != 0)
	{
		ft_command(vars, "rra", 1);
		bot--;
	}
}
