/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:21:52 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/19 16:19:53 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_bfs_chk_block(char c)
{
	if (c == 'P' || c == 'C' || c == 'E')
		return (0);
	return (1);
}

int	ft_bfs_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(ft_bfs_chk_block(map[y][x])))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
