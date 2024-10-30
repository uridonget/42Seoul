/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:27:20 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/12 16:28:47 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	check_door_open(t_museum *mu, t_double_dot pos, double distance)
{
	if (!((int)mu->ray.pos_x / 64 == (int)pos.x / 64
			&& (int)mu->ray.pos_y / 64 == (int)pos.y / 64))
	{
		if (mu->map.map[(int)pos.y / 64][(int)pos.x / 64] == 'D'
			&& distance < 100)
		{
			mu->map.map[(int)pos.y / 64][(int)pos.x / 64] = 'P';
		}
		else if (mu->map.map[(int)pos.y / 64][(int)pos.x / 64] == 'P'
			&& distance < 100)
		{
			mu->map.map[(int)pos.y / 64][(int)pos.x / 64] = 'D';
		}
	}
}

void	check_door(t_museum *mu)
{
	double				dis_horizontal;
	double				dis_vertical;
	t_double_dot		pos_ver;
	t_double_dot		pos_hor;

	pos_hor = find_horizontal(mu, mu->ray.direction, &dis_horizontal, "1DP");
	pos_ver = find_vertical(mu, mu->ray.direction, &dis_vertical, "1DP");
	if (dis_vertical > dis_horizontal)
		check_door_open(mu, pos_hor, dis_horizontal);
	else
		check_door_open(mu, pos_ver, dis_vertical);
}
