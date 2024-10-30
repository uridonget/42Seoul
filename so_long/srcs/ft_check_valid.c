/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:10:35 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/21 11:38:17 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_dfs(char **map, int x, int y)
{
	int			i;
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {1, -1, 0, 0};

	map[y][x] = '1';
	i = 0;
	while (i < 4)
	{
		if (map[y + dy[i]][x + dx[i]] != '1')
		{
			ft_dfs(map, x + dx[i], y + dy[i]);
		}
		i++;
	}
}

static char	**ft_copy_map(t_par *par)
{
	size_t	i;
	size_t	j;
	char	**new_map;
	char	*new_line;

	new_map = (char **)malloc(sizeof(char *) * (par->height + 1));
	if (!(new_map))
		return (0);
	i = -1;
	while (++i < par->height)
	{
		new_line = (char *)malloc(sizeof(char) * (par->width + 1));
		if (!(new_line))
			return (0);
		j = -1;
		while ((par->map)[i][++j])
			new_line[j] = (par->map)[i][j];
		new_line[j] = 0;
		new_map[i] = new_line;
	}
	new_map[i] = 0;
	return (new_map);
}

int	ft_check_valid(t_par *par)
{
	char	**map;

	map = ft_copy_map(par);
	if (!(map))
		return (0);
	ft_dfs(map, (&par->game)->x, (&par->game)->y);
	if (!(ft_bfs_check(map)))
		return (ft_free_map(&map));
	ft_free_map(&map);
	return (1);
}
