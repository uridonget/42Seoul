/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:02:11 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/22 17:23:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_check_block(char c, t_par *par, int y, int x)
{
	if (c == 'P')
	{
		(&par->chk)->p++;
		(&par->game)->x = x;
		(&par->game)->y = y;
	}
	else if (c == 'E')
	{
		(&par->chk)->e++;
		(&par->game)->exit_x = x;
		(&par->game)->exit_y = y;
	}
	else if (c == 'C')
		(&par->chk)->c++;
	else if (c != '0' && c != '1')
	{
		ft_printf("something wrong on the map\n");
		return (0);
	}
	return (1);
}

static int	ft_check_vars(t_par *par)
{
	int	y;
	int	x;

	(&par->chk)->p = 0;
	(&par->chk)->c = 0;
	(&par->chk)->e = 0;
	y = 0;
	while ((par->map)[y])
	{
		x = 0;
		while ((par->map)[y][x])
		{
			if (!(ft_check_block((par->map)[y][x], par, y, x)))
				return (0);
			x++;
		}
		y++;
	}
	if (((&par->chk)->p) != 1)
		return (ft_err_print("number of ramgy is not one\n"));
	if (((&par->chk)->e) != 1)
		return (ft_err_print("number of exit is not one\n"));
	if (((&par->chk)->c) == 0)
		return (ft_err_print("there is no acorn\n"));
	return (1);
}

static int	ft_check_rectangle(t_par *par)
{
	size_t	i;

	i = 0;
	while (i < par->height)
	{
		if (ft_strlen((par->map)[i]) != par->width)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_surround(t_par *par)
{
	size_t	n;
	size_t	i;
	char	**map;

	n = 0;
	map = par->map;
	while (n < par->height)
	{
		if (n == 0 || n == (par->height - 1))
		{
			i = 0;
			while (map[n][i])
			{
				if (map[n][i] != '1')
					return (0);
				i++;
			}
		}
		else
			if (map[n][0] != '1' || map[n][par->width - 1] != '1')
				return (0);
		n++;
	}
	return (1);
}

int	ft_check_map(t_par *par)
{
	if ((par->width > 40) || (par->height > 21))
	{
		ft_printf("Map is too big\n");
		return (0);
	}
	if (!(ft_check_rectangle(par)))
	{
		ft_printf("Map is not rectangular\n");
		return (0);
	}
	if (!(ft_check_surround(par)))
	{
		ft_printf("Map is not surrounded by trees\n");
		return (0);
	}
	if (!(ft_check_vars(par)))
	{
		return (0);
	}
	if (!(ft_check_valid(par)))
	{
		ft_printf("There is no valid path\n");
		return (0);
	}
	return (1);
}
