/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_museum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:24:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 15:23:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_file_name(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (1);
	if ((file_name[len - 1] != 'b') || (file_name[len - 2] != 'u')
		|| (file_name[len - 3] != 'c') || (file_name[len - 4] != '.'))
		return (1);
	return (0);
}

void	init_museum(t_museum *mu, int ac, char **av)
{
	char	*file_name;

	if (ac != 2)
		ft_error("Error\nInvaild argument number");
	file_name = av[1];
	if (check_file_name(file_name))
		ft_error("Error\nInvalid file type");
	ft_memset(&mu->map, 0, sizeof(t_map));
	ft_memset(&mu->ray, 0.0, sizeof(t_ray));
	mu->ray.speed = 1.5;
	ft_memset(&mu->move, 0, sizeof(t_move));
	mu->texture.north.path = NULL;
	mu->texture.south.path = NULL;
	mu->texture.east.path = NULL;
	mu->texture.west.path = NULL;
	mu->texture.floor = -1;
	mu->texture.ceiling = -1;
	open_map_file(file_name, mu);
	make_map(mu);
}
