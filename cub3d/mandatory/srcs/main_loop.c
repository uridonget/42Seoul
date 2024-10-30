/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:59:10 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 16:03:45 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	update_delta(t_ray *ray)
{
	ray->delta_front_x = ray->speed * cos(ray->direction);
	ray->delta_front_y = ray->speed * sin(ray->direction);
	ray->delta_side_x = ray->speed * sin(ray->direction);
	ray->delta_side_y = -1 * ray->speed * cos(ray->direction);
}

static void	check_and_move(double step_x, double step_y, t_museum *mu)
{
	double	temp_x;
	double	temp_y;

	if (step_x > 0)
		temp_x = mu->ray.pos_x + 3 * mu->ray.speed;
	else
		temp_x = mu->ray.pos_x - 3 * mu->ray.speed;
	if (mu->map.map[(int)mu->ray.pos_y / 64][(int)temp_x / 64] == '1')
		return ;
	if (step_y > 0)
		temp_y = mu->ray.pos_y + 3 * mu->ray.speed;
	else
		temp_y = mu->ray.pos_y - 3 * mu->ray.speed;
	if (mu->map.map[(int)temp_y / 64][(int)mu->ray.pos_x / 64] == '1')
		return ;
	if (mu->map.map[(int)temp_y / 64][(int)temp_x / 64] == '1')
		return ;
	mu->ray.pos_x += step_x;
	mu->ray.pos_y += step_y;
}

static void	move_player(t_museum *mu)
{
	if (mu->move.turn_left)
	{
		mu->ray.direction += 0.02;
		if (mu->ray.direction > M_PI * 2)
			mu->ray.direction -= M_PI * 2;
	}
	if (mu->move.turn_right)
	{
		mu->ray.direction -= 0.02;
		if (mu->ray.direction < 0)
			mu->ray.direction += M_PI * 2;
	}
	update_delta(&mu->ray);
	if (mu->move.front)
		check_and_move(mu->ray.delta_front_x, -1 * mu->ray.delta_front_y, mu);
	if (mu->move.left)
		check_and_move(-1 * mu->ray.delta_side_x, mu->ray.delta_side_y, mu);
	if (mu->move.back)
		check_and_move(-1 * mu->ray.delta_front_x, mu->ray.delta_front_y, mu);
	if (mu->move.right)
		check_and_move(mu->ray.delta_side_x, -1 * mu->ray.delta_side_y, mu);
}

int	main_loop(t_museum *mu)
{
	move_player(mu);
	draw_minimap(mu);
	render(mu);
	mlx_put_image_to_window(mu->mlx.mlx, mu->mlx.window, \
			mu->mlx.display.image, 0, 0);
	mlx_put_image_to_window(mu->mlx.mlx, mu->mlx.window, \
			mu->mlx.minimap.image, 30, 30);
	return (1);
}
