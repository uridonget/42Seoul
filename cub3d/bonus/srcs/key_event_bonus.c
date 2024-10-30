/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:36:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 13:19:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	key_press(int keycode, t_museum *mu)
{
	if (keycode == KEY_ESC)
		close_mlx(mu);
	else if (keycode == KEY_SHIFT)
		mu->ray.speed = 3.0;
	else if (keycode == KEY_W)
		mu->move.front = 1;
	else if (keycode == KEY_A)
		mu->move.left = 1;
	else if (keycode == KEY_S)
		mu->move.back = 1;
	else if (keycode == KEY_D)
		mu->move.right = 1;
	else if (keycode == KEY_F)
		check_door(mu);
	else if (keycode == KEY_LEFT)
		mu->move.turn_left = 1;
	else if (keycode == KEY_RIGHT)
		mu->move.turn_right = 1;
	return (1);
}

int	key_release(int keycode, t_museum *mu)
{
	if (keycode == KEY_SHIFT)
		mu->ray.speed = 1.5;
	else if (keycode == KEY_W)
		mu->move.front = 0;
	else if (keycode == KEY_A)
		mu->move.left = 0;
	else if (keycode == KEY_S)
		mu->move.back = 0;
	else if (keycode == KEY_D)
		mu->move.right = 0;
	else if (keycode == KEY_LEFT)
		mu->move.turn_left = 0;
	else if (keycode == KEY_RIGHT)
		mu->move.turn_right = 0;
	return (1);
}
