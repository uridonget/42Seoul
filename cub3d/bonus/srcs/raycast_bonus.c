/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:08:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 17:14:48 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	draw_square(t_museum *mu, t_texture_file texture,
	t_square square, double texture_index)
{
	int		tx;
	double	ty;
	double	ty_step;
	int		color;
	int		index;

	ty = 0;
	ty_step = (double)texture.height / (double)square.height;
	if (square.height > mu->mlx.display.height)
	{	
		ty = (square.height - mu->mlx.display.height) / 2.0 * ty_step;
		square.height = mu->mlx.display.height;
	}
	tx = (texture_index - ((int)texture_index >> 6 << 6))
		/ 64.0 * texture.width;
	index = square.y;
	while (index < square.y + square.height)
	{
		color = ((int *)texture.image_addr)[(int)ty * texture.height + tx];
		set_color(mu, square, color, index);
		ty += ty_step;
		index += 1;
	}
}

static void	raycast_hor(t_museum *mu, t_square square,
	t_double_dot pos, double direction)
{
	if (mu->map.map[(int)pos.y / 64][(int)pos.x / 64] == 'D')
		draw_square(mu, mu->texture.door, square, pos.x);
	else if (sin(direction) > 0)
		draw_square(mu, mu->texture.north, square, pos.x);
	else
		draw_square(mu, mu->texture.south, square, pos.x);
}

static void	raycast_ver(t_museum *mu, t_square square,
	t_double_dot pos, double direction)
{
	if (mu->map.map[(int)pos.y / 64][(int)pos.x / 64] == 'D')
		draw_square(mu, mu->texture.door, square, pos.y);
	else if (cos(direction) > 0)
		draw_square(mu, mu->texture.east, square, pos.y);
	else
		draw_square(mu, mu->texture.west, square, pos.y);
}

void	raycast(t_museum *mu, double direction, int displayIndex)
{
	double				dis_horizontal;
	double				dis_vertical;
	t_square			square;
	t_double_dot		pos_ver;
	t_double_dot		pos_hor;

	pos_hor = find_horizontal(mu, direction, &dis_horizontal, "1D");
	pos_ver = find_vertical(mu, direction, &dis_vertical, "1D");
	if (dis_vertical > dis_horizontal)
	{
		dis_horizontal = fix_angle(dis_horizontal,
				mu->ray.direction, direction);
		square_update(mu, &square, displayIndex, dis_horizontal);
		raycast_hor(mu, square, pos_hor, direction);
	}
	else
	{
		dis_vertical = fix_angle(dis_vertical, mu->ray.direction, direction);
		square_update(mu, &square, displayIndex, dis_vertical);
		raycast_ver(mu, square, pos_ver, direction);
	}
}
