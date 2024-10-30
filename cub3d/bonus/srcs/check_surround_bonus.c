/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:43:43 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 13:54:34 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	check_dfs(char **map, int x, int y)
{
	size_t		i;
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {1, -1, 0, 0};

	map[y][x] = '1';
	i = 0;
	while (i < 4)
	{
		if (map[y + dy[i]][x + dx[i]] != '1')
		{
			if (map[y + dy[i]][x + dx[i]] == ' ')
				return (1);
			if (check_dfs(map, x + dx[i], y + dy[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_surround(char **map, t_museum *mu)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i] && (i <= mu->map.height))
	{
		j = 1;
		while (map[i][j] && (j <= mu->map.width))
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
				if (check_dfs(map, j, i))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
