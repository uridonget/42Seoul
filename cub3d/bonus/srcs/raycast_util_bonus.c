/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   racast_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:45:30 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/11 16:47:11 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	set_color(t_museum *mu, t_square square, int color, int index)
{
	int	image_index;
	int	display_size;

	display_size = mu->mlx.display.height * mu->mlx.display.width;
	image_index = index * mu->mlx.display.width + square.x;
	if (image_index < display_size)
		((int *)mu->mlx.display.image_address)[image_index] = color;
}

double	fix_angle(double distance, double playerAngle, double rayAngle)
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

void	square_update(t_museum *mu, t_square *square,
	int displayIndex, double distance)
{
	square->height = (64) * (mu->mlx.display.height) / (int)distance;
	square->x = displayIndex;
	square->y = (mu->mlx.display.height >> 1) - (square->height >> 1);
	if (square->height > mu->mlx.display.height)
		square->y = 0;
}
