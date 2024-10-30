/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:45:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 16:49:46 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	check_texture(char *trim, int *cnt, t_museum *mu)
{
	if (ft_strncmp(trim, "NO", 2) == 0)
		set_north_texture(trim, cnt, mu);
	else if (ft_strncmp(trim, "SO", 2) == 0)
		set_south_texture(trim, cnt, mu);
	else if (ft_strncmp(trim, "WE", 2) == 0)
		set_west_texture(trim, cnt, mu);
	else if (ft_strncmp(trim, "EA", 2) == 0)
		set_east_texture(trim, cnt, mu);
	else if (ft_strncmp(trim, "DO", 2) == 0)
		set_door_texture(trim, cnt, mu);
	else if (ft_strncmp(trim, "SP", 2) == 0)
		set_sprite_texture(trim, cnt, mu);
	else
		return (0);
	return (1);
}

static void	check_line(char *line, int *cnt, t_museum *mu)
{
	char	*trim;

	if (!(line))
		return ;
	trim = ft_strtrim(line, " 	");
	if (check_texture(trim, cnt, mu))
		;
	else if (ft_strncmp(trim, "F", 1) == 0)
		set_floor(trim, cnt, mu);
	else if (ft_strncmp(trim, "C", 1) == 0)
		set_ceiling(trim, cnt, mu);
	else if (*cnt == 9)
		map_lst_add_back(&(mu->map.lst), map_lst_new(line));
	else if (ft_strlen(trim))
		ft_error("Error\ninvalid map!");
	free(trim);
}

static int	read_map_file(int fd, t_museum *mu)
{
	int		cnt;
	char	*line;

	cnt = 0;
	line = get_next_line(fd);
	check_line(line, &cnt, mu);
	while (line)
	{
		if (cnt == 8)
		{
			cnt += 1;
			free(line);
		}
		if (cnt != 9)
			free(line);
		line = get_next_line(fd);
		check_line(line, &cnt, mu);
	}
	return (0);
}

int	open_map_file(char *file_name, t_museum *mu)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFail to open map file");
	read_map_file(fd, mu);
	close(fd);
	return (0);
}
