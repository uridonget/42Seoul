/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hor_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:50:34 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/12 16:45:22 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	update_hor_delta_up(t_museum *mu, t_double_dot *p,
	t_double_dot *delta, double atan)
{
	p->y = (((int)(mu->ray.pos_y) >> 6) << 6) - 0.0001;
	delta->y = -64;
	p->x = atan * (mu->ray.pos_y - p->y) + mu->ray.pos_x;
	delta->x = -1.0 * delta->y * atan;
}

static void	update_hor_delta_down(t_museum *mu, t_double_dot *p,
	t_double_dot *delta, double atan)
{
	p->y = (((int)(mu->ray.pos_y) >> 6) << 6) + 64;
	delta->y = 64;
	p->x = atan * (mu->ray.pos_y - p->y) + mu->ray.pos_x;
	delta->x = -1.0 * delta->y * atan;
}

static int	is_set(char *set, char c)
{
	int	index;

	index = 0;
	while (set[index] != 0)
	{
		if (set[index] == c)
			return (1);
		index += 1;
	}
	return (0);
}

static void	update_dot_dump(t_double_dot *p, double *distance)
{
	p->x = 0;
	p->y = 0;
	*distance = 1000000;
}

t_double_dot	find_horizontal(t_museum *mu, double direction,
					double *distance, char *set)
{
	t_double_dot	p;
	t_double_dot	delta;
	double			atan;

	atan = 1.0 / tan(direction);
	if (sin(direction) > 0.001)
		update_hor_delta_up(mu, &p, &delta, atan);
	else if (sin(direction) < -0.001)
		update_hor_delta_down(mu, &p, &delta, atan);
	else
	{
		update_dot_dump(&p, distance);
		return (p);
	}
	while ((int)p.y / 64 >= 0 && (int)p.y / 64 < (int)mu->map.height
		&& (int)p.x / 64 >= 0 && (int)p.x / 64 < (int)mu->map.width)
	{
		if (is_set(set, mu->map.map[(int)p.y / 64][(int)p.x / 64]))
			break ;
		p.x += delta.x;
		p.y += delta.y;
	}
	*distance = cos(direction) * (p.x - mu->ray.pos_x)
		- sin(direction) * (p.y - mu->ray.pos_y);
	return (p);
}
