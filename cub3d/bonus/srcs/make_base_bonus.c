/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_base_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:51:55 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/12 16:16:19 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static char	*make_base_line(t_museum *mu)
{
	char				*line;
	unsigned long		i;

	line = (char *)malloc(sizeof(char) * (mu->map.width + 3));
	if (!(line))
		exit(EXIT_FAILURE);
	line[mu->map.width + 2] = 0;
	i = 0;
	while (i < mu->map.width + 2)
	{
		line[i] = ' ';
		i++;
	}
	return (line);
}

void	make_base(t_museum *mu)
{
	unsigned long	i;

	mu->map.map = (char **)malloc(sizeof(char *) * (mu->map.height + 3));
	if (!(mu->map.map))
		exit(EXIT_FAILURE);
	mu->map.map[mu->map.height + 2] = 0;
	i = 0;
	while (i < mu->map.height + 2)
	{
		mu->map.map[i] = make_base_line(mu);
		i++;
	}
}
