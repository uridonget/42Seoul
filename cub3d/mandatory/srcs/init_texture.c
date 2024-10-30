/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:49:17 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 14:45:54 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	texture_to_image(t_museum *mu)
{
	mu->texture.north.image = mlx_xpm_file_to_image(&(mu->mlx.mlx),
			mu->texture.north.path, &(mu->texture.north.width),
			&(mu->texture.north.height));
	if (!mu->texture.north.image)
		ft_error("Error\nInvalid north texture path");
	free(mu->texture.north.path);
	mu->texture.west.image = mlx_xpm_file_to_image(&(mu->mlx.mlx),
			mu->texture.west.path, &(mu->texture.west.width),
			&(mu->texture.west.height));
	if (!mu->texture.west.image)
		ft_error("Error\nInvalid west texture path");
	free(mu->texture.west.path);
	mu->texture.south.image = mlx_xpm_file_to_image(&(mu->mlx.mlx),
			mu->texture.south.path, &(mu->texture.south.width),
			&(mu->texture.south.height));
	if (!mu->texture.south.image)
		ft_error("Error\nInvalid south texture path");
	free(mu->texture.south.path);
	mu->texture.east.image = mlx_xpm_file_to_image(&(mu->mlx.mlx),
			mu->texture.east.path, &(mu->texture.east.width),
			&(mu->texture.east.height));
	if (!mu->texture.east.image)
		ft_error("Error\nInvalid east texture path");
	free(mu->texture.east.path);
}

static void	texture_get_data_addr(t_museum *mu)
{
	mu->texture.north.image_addr = mlx_get_data_addr(mu->texture.north.image,
			&mu->texture.north.bit, &mu->texture.north.image_size,
			&mu->texture.north.endian);
	mu->texture.west.image_addr = mlx_get_data_addr(mu->texture.west.image,
			&mu->texture.west.bit, &mu->texture.west.image_size,
			&mu->texture.west.endian);
	mu->texture.south.image_addr = mlx_get_data_addr(mu->texture.south.image,
			&mu->texture.south.bit, &mu->texture.south.image_size,
			&mu->texture.south.endian);
	mu->texture.east.image_addr = mlx_get_data_addr(mu->texture.east.image,
			&mu->texture.east.bit, &mu->texture.east.image_size,
			&mu->texture.east.endian);
}

void	init_texture(t_museum *mu)
{
	texture_to_image(mu);
	texture_get_data_addr(mu);
}
