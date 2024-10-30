/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:15:47 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/10 16:18:51 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	clear(t_museum *map)
{
	int	index;

	index = 0;
	while (index < map->mlx.display.height * map->mlx.display.width / 2)
	{
		((int *)(map->mlx.display.image_address))[index] = map->texture.ceiling;
		index++;
	}
	while (index < map->mlx.display.height * map->mlx.display.width)
	{
		((int *)(map->mlx.display.image_address))[index] = map->texture.floor;
		index++;
	}
}

void	render(t_museum *map)
{
	double	dir;
	int		index;

	index = 0;
	dir = map->ray.direction + 0.6;
	if (dir < 0)
		dir += M_PI * 2;
	clear(map);
	while (index < 1920)
	{
		dir -= 0.000625;
		if (dir > M_PI * 2)
			dir -= M_PI * 2;
		raycast(map, dir, index);
		index += 1;
	}
}
