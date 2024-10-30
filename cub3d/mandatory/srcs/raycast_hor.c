/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:50:34 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/14 15:06:04 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

double	find_horizontal(t_museum *mu, double direction, double *distance)
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
		*distance = 1000000;
		return (1000000);
	}
	while ((int)p.y / 64 >= 0 && (int)p.y / 64 < (int)mu->map.height
		&& (int)p.x / 64 >= 0 && (int)p.x / 64 < (int)mu->map.width)
	{
		if (mu->map.map[(int)p.y / 64][(int)p.x / 64] == '1')
			break ;
		p.x += delta.x;
		p.y += delta.y;
	}
	*distance = cos(direction) * (p.x - mu->ray.pos_x)
		- sin(direction) * (p.y - mu->ray.pos_y);
	return (p.x);
}
