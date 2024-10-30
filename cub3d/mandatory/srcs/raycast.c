/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:08:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 17:15:43 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

typedef struct s_square
{
	int			x;
	int			y;
	int			height;
}	t_square;

static void	set_color(t_museum *mu, t_square square, int color, int index)
{
	int	image_index;
	int	display_size;

	display_size = mu->mlx.display.height * mu->mlx.display.width;
	image_index = index * mu->mlx.display.width + square.x;
	if (image_index < display_size)
		((int *)mu->mlx.display.image_address)[image_index] = color;
}

void	draw_square(t_museum *mu, t_texture_file texture,
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

static double	fix_angle(double distance, double playerAngle, double rayAngle)
{
	double	angle;

	angle = playerAngle - rayAngle;
	if (angle < 0)
		angle += M_PI * 2;
	else if (angle > M_PI * 2)
		angle -= M_PI * 2;
	distance = distance * cos(angle);
	if ((int)distance == 0)
		distance = 1;
	return (distance);
}

static void	square_update(t_museum *mu, t_square *square,
	int displayIndex, double distance)
{
	square->height = (64) * (mu->mlx.display.height) / (int)distance;
	square->x = displayIndex;
	square->y = (mu->mlx.display.height >> 1) - (square->height >> 1);
	if (square->height > mu->mlx.display.height)
		square->y = 0;
}

void	raycast(t_museum *mu, double direction, int displayIndex)
{
	double				dis_horizontal;
	double				dis_vertical;
	t_square			square;
	double				pos_vertical;
	double				pos_horizontal;

	pos_horizontal = find_horizontal(mu, direction, &dis_horizontal);
	pos_vertical = find_vertical(mu, direction, &dis_vertical);
	if (dis_vertical > dis_horizontal)
	{
		dis_horizontal = fix_angle(dis_horizontal,
				mu->ray.direction, direction);
		square_update(mu, &square, displayIndex, dis_horizontal);
		if (sin(direction) > 0)
			draw_square(mu, mu->texture.north, square, pos_horizontal);
		else
			draw_square(mu, mu->texture.south, square, pos_horizontal);
		return ;
	}
	dis_vertical = fix_angle(dis_vertical, mu->ray.direction, direction);
	square_update(mu, &square, displayIndex, dis_vertical);
	if (cos(direction) > 0)
		draw_square(mu, mu->texture.east, square, pos_vertical);
	else
		draw_square(mu, mu->texture.west, square, pos_vertical);
}
