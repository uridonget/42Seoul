/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:54:29 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/14 17:20:12 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	free_all_arg(t_museum *mu)
{
	free(mu->texture.north.path);
	free(mu->texture.south.path);
	free(mu->texture.east.path);
	free(mu->texture.west.path);
	free(mu->texture.door.path);
	destroy_sprite(mu);
	free_strs(mu->map.map);
}

int	main(int ac, char *av[])
{
	t_museum	mu;

	init_museum(&mu, ac, av);
	if (check_museum(&mu))
	{
		free_all_arg(&mu);
		return (1);
	}
	init_mlx(&mu);
	return (0);
}
