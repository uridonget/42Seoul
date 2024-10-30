/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:54:29 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/14 17:21:04 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_all_arg(t_museum *mu)
{
	free_strs(mu->map.map);
	free(mu->texture.north.path);
	free(mu->texture.south.path);
	free(mu->texture.west.path);
	free(mu->texture.east.path);
}

int	main(int ac, char *av[])
{
	t_museum	mu;

	init_museum(&mu, ac, av);
	if (check_museum(&mu))
	{
		free_all_arg(&mu);
		ft_error("Error\nInvalid Map!");
	}
	init_mlx(&mu);
	return (0);
}
