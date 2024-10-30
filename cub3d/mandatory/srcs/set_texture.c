/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:36:55 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 14:47:13 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_north_texture(char *trim, int *cnt, t_museum *mu)
{
	char	*path;

	if (mu->texture.north.path)
		ft_error("Error\nInvalid North Texture");
	path = ft_substr(trim, 2, ft_strlen(trim) - 2);
	mu->texture.north.path = ft_strtrim(path, " 	");
	free(path);
	*cnt += 1;
}

void	set_south_texture(char *trim, int *cnt, t_museum *mu)
{
	char	*path;

	if (mu->texture.south.path)
		ft_error("Error\nInvalid South Texture");
	path = ft_substr(trim, 2, ft_strlen(trim) - 2);
	mu->texture.south.path = ft_strtrim(path, " 	");
	free(path);
	*cnt += 1;
}

void	set_east_texture(char *trim, int *cnt, t_museum *mu)
{
	char	*path;

	if (mu->texture.east.path)
		ft_error("Error\nInvalid East Texture");
	path = ft_substr(trim, 2, ft_strlen(trim) - 2);
	mu->texture.east.path = ft_strtrim(path, " 	");
	free(path);
	*cnt += 1;
}

void	set_west_texture(char *trim, int *cnt, t_museum *mu)
{
	char	*path;

	if (mu->texture.west.path)
		ft_error("Error\nInvalid West Texture");
	path = ft_substr(trim, 2, ft_strlen(trim) - 2);
	mu->texture.west.path = ft_strtrim(path, " 	");
	free(path);
	*cnt += 1;
}
