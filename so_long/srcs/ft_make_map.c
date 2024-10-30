/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:57:57 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/22 17:22:07 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_make_map(t_par *par)
{
	int		fd;
	size_t	i;
	char	*line;

	par->map = (char **)malloc(sizeof(char *) * (par->height + 1));
	if (!(par->map))
	{
		ft_printf("malloc failed\n");
		return (0);
	}
	fd = open(par->file_name, O_RDONLY);
	if (fd < 0)
		return (ft_err_print("fail to open file\n"));
	line = get_next_line(fd);
	i = 0;
	while (i < par->height)
	{
		(par->map)[i] = line;
		line = get_next_line(fd);
		i++;
	}
	(par->map)[i] = 0;
	close(fd);
	return (1);
}
