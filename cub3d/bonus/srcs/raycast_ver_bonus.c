/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ver_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:50:18 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/12 16:45:30 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

t_double_dot	find_vertical(t_museum *mu, double direction,
					double *distance, char *set)
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
