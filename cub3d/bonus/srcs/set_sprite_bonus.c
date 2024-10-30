/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:05:09 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/14 14:40:01 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	*open_xpm(t_museum *mu, t_texture_file *texture, int index)
{
	void	*res;

	res = mlx_xpm_file_to_image(&mu->mlx.mlx, texture[index].path,
			&(texture[index].width), &(texture[index].height));
	return (res);
}

static void	set_normal_state_texture(char *trim, t_museum *mu)
{
	char	*file_path;
	char	*file_name;
	char	*num;
	int		index;

	mu->texture.normal_state = malloc(sizeof(t_texture_file) * 20);
	if (!mu->texture.normal_state)
		exit(EXIT_FAILURE);
	file_path = ft_strjoin(trim, "normal/");
	index = 0;
	while (index < 20)
	{
		num = ft_itoa(index);
		file_name = ft_strjoin(num, ".xpm");
		free(num);
		mu->texture.normal_state[index].path = ft_strjoin(file_path, file_name);
		free(file_name);
		mu->texture.normal_state[index].image
			= open_xpm(mu, mu->texture.normal_state, index);
		if (!mu->texture.normal_state[index].image)
			ft_error("Error\ninvalid sprite normal");
		free(mu->texture.normal_state[index].path);
		index++;
	}
	free(file_path);
}

static void	set_left_punch_texture(char *trim, t_museum *mu)
{
	char	*file_path;
	char	*file_name;
	char	*num;
	int		index;

	mu->texture.left_punch = malloc(sizeof(t_texture_file) * 14);
	if (!mu->texture.left_punch)
		exit(EXIT_FAILURE);
	file_path = ft_strjoin(trim, "left/");
	index = 0;
	while (index < 14)
	{
		num = ft_itoa(index);
		file_name = ft_strjoin(num, ".xpm");
		free(num);
		mu->texture.left_punch[index].path = ft_strjoin(file_path, file_name);
		free(file_name);
		mu->texture.left_punch[index].image
			= open_xpm(mu, mu->texture.left_punch, index);
		if (!mu->texture.left_punch[index].image)
			ft_error("Error\ninvalid sprite left_punch");
		free(mu->texture.left_punch[index].path);
		index++;
	}
	free(file_path);
}

static void	set_right_punch_texture(char *trim, t_museum *mu)
{
	char	*file_path;
	char	*file_name;
	char	*num;
	int		index;

	mu->texture.right_punch = malloc(sizeof(t_texture_file) * 9);
	if (!mu->texture.right_punch)
		exit(EXIT_FAILURE);
	file_path = ft_strjoin(trim, "right/");
	index = 0;
	while (index < 9)
	{
		num = ft_itoa(index);
		file_name = ft_strjoin(num, ".xpm");
		free(num);
		mu->texture.right_punch[index].path = ft_strjoin(file_path, file_name);
		free(file_name);
		mu->texture.right_punch[index].image
			= open_xpm(mu, mu->texture.right_punch, index);
		if (!mu->texture.right_punch[index].image)
			ft_error("Error\ninvalid sprite right_punch");
		free(mu->texture.right_punch[index].path);
		index++;
	}
	free(file_path);
}

void	set_sprite_texture(char *trim, int *cnt, t_museum *mu)
{
	char	*path;
	char	*path_trim;

	path = ft_substr(trim, 2, ft_strlen(trim) - 2);
	path_trim = ft_strtrim(path, " 	");
	free(path);
	set_normal_state_texture(path_trim, mu);
	set_left_punch_texture(path_trim, mu);
	set_right_punch_texture(path_trim, mu);
	free(path_trim);
	*cnt += 1;
}
