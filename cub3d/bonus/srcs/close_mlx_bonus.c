/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:15:55 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 13:28:44 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	destroy_texture(t_museum *mu)
{
	mlx_destroy_image(mu->mlx.mlx, mu->texture.east.image);
	mlx_destroy_image(mu->mlx.mlx, mu->texture.west.image);
	mlx_destroy_image(mu->mlx.mlx, mu->texture.north.image);
	mlx_destroy_image(mu->mlx.mlx, mu->texture.south.image);
	mlx_destroy_image(mu->mlx.mlx, mu->texture.door.image);
}

void	destroy_sprite(t_museum *mu)
{
	int	index;

	index = 0;
	while (index < 20)
	{
		mlx_destroy_image(mu->mlx.mlx, mu->texture.normal_state[index].image);
		index += 1;
	}
	free(mu->texture.normal_state);
	index = 0;
	while (index < 14)
	{
		mlx_destroy_image(mu->mlx.mlx, mu->texture.left_punch[index].image);
		index += 1;
	}
	free(mu->texture.left_punch);
	index = 0;
	while (index < 9)
	{
		mlx_destroy_image(mu->mlx.mlx, mu->texture.right_punch[index].image);
		index += 1;
	}
	free(mu->texture.right_punch);
}

int	close_mlx(t_museum *mu)
{
	mlx_destroy_image(mu->mlx.mlx, mu->mlx.display.image);
	mlx_destroy_image(mu->mlx.mlx, mu->mlx.minimap.image);
	destroy_texture(mu);
	destroy_sprite(mu);
	mlx_destroy_window(mu->mlx.mlx, mu->mlx.window);
	free_strs(mu->map.map);
	exit(0);
}
