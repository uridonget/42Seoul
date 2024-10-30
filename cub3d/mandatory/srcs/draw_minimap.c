/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:03:55 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 16:06:17 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_minimap_wall(t_museum *mu,
t_int_dot index, t_double_dot map_pos)
{
	if (map_pos.x >= 0 && map_pos.x < (mu->map.width + 1) * 64
		&& map_pos.y >= 0 && map_pos.y < (mu->map.height + 1) * 64)
		if (mu->map.map[(int)map_pos.y / 64][(int)map_pos.x / 64] == '1')
		((int *)(mu->mlx.minimap.image_address))
			[index.x + index.y * 320] = 0x00ffffff;
}

static void	draw_minimap_walls(t_museum *mu)
{
	t_int_dot		index;
	t_double_dot	start;
	t_double_dot	map_pos;
	double			c;
	double			s;

	c = cos(mu->ray.direction);
	s = sin(mu->ray.direction);
	index.y = 0;
	start.x = (mu->ray.pos_x) + 320 * (c - s);
	start.y = (mu->ray.pos_y) - 320 * (c + s);
	while (index.y < 320)
	{
		map_pos.x = start.x - index.y * c * 2;
		map_pos.y = start.y + index.y * s * 2;
		index.x = 0;
		while (index.x < 320)
		{
			draw_minimap_wall(mu, index, map_pos);
			index.x += 1;
			map_pos.x += s * 2;
			map_pos.y += c * 2;
		}
		index.y += 1;
	}
}

static void	draw_player(t_museum *mu)
{
	t_int_dot	index;
	int			player_pos;

	player_pos = mu->mlx.minimap.width / 2 - 3
		+ (mu->mlx.minimap.height / 2 - 3) * mu->mlx.minimap.height;
	index.y = 0;
	while (index.y < 7)
	{
		index.x = 0;
		while (index.x < 7)
		{
			((int *)(mu->mlx.minimap.image_address))
			[player_pos + mu->mlx.minimap.height
				* index.y + index.x] = 0x00ff0000;
			index.x += 1;
		}
		index.y += 1;
	}
}

void	draw_minimap(t_museum *mu)
{
	int	index;

	index = 0;
	while (index < mu->mlx.minimap.width * mu->mlx.minimap.height)
	{
		((int *)(mu->mlx.minimap.image_address))[index] = 0;
		index += 1;
	}
	draw_minimap_walls(mu);
	draw_player(mu);
}
