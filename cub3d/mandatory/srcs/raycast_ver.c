/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:50:18 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/14 15:06:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	update_ver_delta_left(t_museum *mu, t_double_dot *p,
	t_double_dot *delta, double tan_v)
{
	p->x = (((int)(mu->ray.pos_x) >> 6) << 6) - 0.0001;
	p->y = tan_v * (mu->ray.pos_x - p->x) + mu->ray.pos_y;
	delta->x = -64;
	delta->y = -1.0 * delta->x * tan_v;
}

static void	update_ver_delta_right(t_museum *mu, t_double_dot *p,
	t_double_dot *delta, double tan_v)
{
	p->x = (((int)(mu->ray.pos_x) >> 6) << 6) + 64;
	p->y = tan_v * (mu->ray.pos_x - p->x) + mu->ray.pos_y;
	delta->x = 64;
	delta->y = -1.0 * delta->x * tan_v;
}

double	find_vertical(t_museum *mu, double direction, double *distance)
{
	t_double_dot	p;
	t_double_dot	delta;
	double			tan_v;

	tan_v = tan(direction);
	if (cos(direction) > 0.001)
		update_ver_delta_right(mu, &p, &delta, tan_v);
	else if (cos(direction) < -0.001)
		update_ver_delta_left(mu, &p, &delta, tan_v);
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
	return (p.y);
}
