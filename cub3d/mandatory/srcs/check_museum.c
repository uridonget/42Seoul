/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_museum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:53:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 16:54:54 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	**copy_map(t_museum *mu)
{
	char	**replica;
	int		i;

	replica = (char **)malloc(sizeof(char *) * (mu->map.height + 3));
	if (!(replica))
		exit(EXIT_FAILURE);
	replica[mu->map.height + 2] = NULL;
	i = 0;
	while (mu->map.map[i])
	{
		replica[i] = ft_strdup(mu->map.map[i]);
		i++;
	}
	return (replica);
}

static void	set_start_point(int y, int x, t_museum *mu, char c)
{
	mu->ray.pos_x = x * 64 + 32;
	mu->ray.pos_y = y * 64 + 32;
	if (c == 'E')
		mu->ray.direction = 0;
	else if (c == 'S')
		mu->ray.direction = M_PI + M_PI_2;
	else if (c == 'W')
		mu->ray.direction = M_PI;
	else if (c == 'N')
		mu->ray.direction = M_PI_2;
	update_delta(&mu->ray);
}

static int	is_set(char *set, char c)
{
	int	index;

	index = 0;
	while (set[index] != 0)
	{
		if (set[index] == c)
			return (1);
		index += 1;
	}
	return (0);
}

static int	check_valid_input(char **map, t_museum *mu)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_set("NSWE", map[i][j]) == 1)
			{
				if (cnt != 0)
					return (1);
				cnt = 1;
				set_start_point(i, j, mu, map[i][j]);
			}
			else if (is_set("10 ", map[i][j]) == 0)
				return (1);
		}
	}
	if (cnt == 0)
		return (1);
	return (0);
}

int	check_museum(t_museum *mu)
{
	char	**replica;

	replica = copy_map(mu);
	if (check_valid_input(replica, mu))
	{
		free_strs(replica);
		return (1);
	}
	if (check_surround(replica, mu))
	{
		free_strs(replica);
		return (1);
	}
	free_strs(replica);
	return (0);
}
