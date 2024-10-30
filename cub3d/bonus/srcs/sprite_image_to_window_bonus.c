/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_image_to_window_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:38:07 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/12 16:46:12 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	sprite_image_to_window(t_museum *mu)
{
	if (mu->move.state == NORMAL_STATE)
	{
		mlx_put_image_to_window(mu->mlx.mlx, mu->mlx.window,
			mu->texture.normal_state[mu->mlx.cnt].image, 0, 0);
	}
	else if (mu->move.state == LEFT_PUNCH)
	{
		mlx_put_image_to_window(mu->mlx.mlx, mu->mlx.window,
			mu->texture.left_punch[mu->mlx.cnt].image, 0, 0);
	}
	else if (mu->move.state == RIGHT_PUNCH)
	{
		mlx_put_image_to_window(mu->mlx.mlx, mu->mlx.window,
			mu->texture.right_punch[mu->mlx.cnt].image, 0, 0);
	}
}

void	reset_sprite_cnt(t_museum *mu)
{
	if (mu->move.state == NORMAL_STATE)
	{
		if (mu->mlx.cnt >= 20)
			mu->mlx.cnt = 0;
	}
	else if (mu->move.state == LEFT_PUNCH)
	{
		if (mu->mlx.cnt >= 13)
		{
			mu->mlx.cnt = 0;
			mu->move.state = NORMAL_STATE;
		}
	}
	else if (mu->move.state == RIGHT_PUNCH)
	{
		if (mu->mlx.cnt >= 8)
		{
			mu->mlx.cnt = 0;
			mu->move.state = NORMAL_STATE;
		}
	}
}
