/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:32:52 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/11 12:34:45 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	angle_event(int keycode, t_museum *mu)
{
	if (keycode == KEY_LEFT)
	{
		mu->ray.direction += 0.001;
		if (mu->ray.direction > M_PI * 2)
			mu->ray.direction -= M_PI * 2;
		update_delta(&mu->ray);
	}
	else if (keycode == KEY_RIGHT)
	{
		mu->ray.direction -= 0.01;
		if (mu->ray.direction < 0)
			mu->ray.direction += M_PI * 2;
		update_delta(&mu->ray);
	}
	return (1);
}
