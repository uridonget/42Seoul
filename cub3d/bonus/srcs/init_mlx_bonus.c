/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:13:20 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 14:37:35 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

int	move_mouse(int x, int y, t_museum *mu)
{
	static int	xpos;
	static int	first;

	(void)y;
	if (first == 0)
	{
		first = 1;
		xpos = x;
		return (1);
	}
	if (x <= 0 || x >= 1920)
	{
		xpos = 900;
		mlx_mouse_move(mu->mlx.window, 900, 400);
	}
	else
	{
		mu->ray.direction += (double)(xpos - x) / 1920.0 * M_PI;
		if (mu->ray.direction > M_PI * 2)
			mu->ray.direction -= M_PI * 2;
		else if (mu->ray.direction < 0)
			mu->ray.direction += M_PI * 2;
		xpos = x;
	}
	return (1);
}

int	mouse_press(int button, int x, int y, t_museum *mu)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (mu->move.state != NORMAL_STATE)
			return (1);
		mu->mlx.cnt = 0;
		mu->move.state = LEFT_PUNCH;
	}
	else if (button == 2)
	{
		if (mu->move.state != NORMAL_STATE)
			return (1);
		mu->mlx.cnt = 0;
		mu->move.state = RIGHT_PUNCH;
	}
	return (1);
}

void	init_mlx(t_museum *mu)
{
	mu->mlx.cnt = 0;
	mu->mlx.mlx = mlx_init();
	if (!mu->mlx.mlx)
		ft_error("mlx init error");
	init_minimap(mu);
	init_display(mu);
	init_texture(mu);
	mlx_hook(mu->mlx.window, 2, (1L << 0), key_press, mu);
	mlx_hook(mu->mlx.window, 3, (1L << 0), key_release, mu);
	mlx_hook(mu->mlx.window, 17, (1L << 17), close_mlx, mu);
	mlx_hook (mu->mlx.window, 06, (1L << 6), move_mouse, mu);
	mlx_mouse_hook (mu->mlx.window, mouse_press, mu);
	mlx_mouse_hide();
	mlx_loop_hook(mu->mlx.mlx, main_loop, mu);
	mlx_loop(mu->mlx.mlx);
}
