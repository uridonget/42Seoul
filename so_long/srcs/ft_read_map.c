/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:58:37 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/22 17:21:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_read_map(t_par *par)
{
	int		fd;
	char	*line;

	fd = open(par->file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fail to open file\n");
		return (0);
	}
	line = get_next_line(fd);
	par->width = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		par->height++;
	}
	close(fd);
	return (1);
}
