/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:13:20 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 15:53:26 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_minimap(t_museum *mu)
{
	mu->mlx.minimap.width = 320;
	mu->mlx.minimap.height = 320;
	mu->mlx.minimap.image = mlx_new_image(mu->mlx.mlx,
			mu->mlx.minimap.width, mu->mlx.minimap.height);
	if (mu->mlx.minimap.image == 0)
		exit(1);
	mu->mlx.minimap.image_address = mlx_get_data_addr(
			mu->mlx.minimap.image, &(mu->mlx.bit),
			&(mu->mlx.minimap.image_size), &(mu->mlx.endian));
	if (mu->mlx.bit != 32 || mu->mlx.endian != 0)
		exit(1);
}

static void	init_display(t_museum *mu)
{
	mu->mlx.display.width = 1920;
	mu->mlx.display.height = 1080;
	mu->mlx.window = mlx_new_window(mu->mlx.mlx,
			mu->mlx.display.width, mu->mlx.display.height, "cub3D");
	if (mu->mlx.window == 0)
		exit(1);
	mu->mlx.display.image = mlx_new_image(mu->mlx.mlx,
			mu->mlx.display.width, mu->mlx.display.height);
	if (mu->mlx.display.image == 0)
		exit(1);
	mu->mlx.display.image_address = mlx_get_data_addr(mu->mlx.display.image,
			&(mu->mlx.bit), &(mu->mlx.display.image_size), &(mu->mlx.endian));
	if (mu->mlx.bit != 32 || mu->mlx.endian != 0)
		exit(1);
}

void	init_mlx(t_museum *mu)
{
	mu->mlx.mlx = mlx_init();
	if (!mu->mlx.mlx)
		exit(EXIT_FAILURE);
	init_minimap(mu);
	init_display(mu);
	init_texture(mu);
	mlx_hook(mu->mlx.window, 2, (1L << 0), key_press, mu);
	mlx_hook(mu->mlx.window, 3, (1L << 0), key_release, mu);
	mlx_hook(mu->mlx.window, 17, (1L << 17), close_mlx, mu);
	mlx_loop_hook(mu->mlx.mlx, main_loop, mu);
	mlx_loop(mu->mlx.mlx);
}
