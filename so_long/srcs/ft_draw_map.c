/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:16:17 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/13 17:34:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_img(t_par *par)
{
	(&par->img)->grass = mlx_xpm_file_to_image(par->mlx, \
			"./img/grass.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->tree = mlx_xpm_file_to_image(par->mlx, \
			"./img/tree.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->acorn = mlx_xpm_file_to_image(par->mlx, \
			"./img/acorn.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->rocket = mlx_xpm_file_to_image(par->mlx, \
			"./img/rocket.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->ramgy_left = mlx_xpm_file_to_image(par->mlx, \
			"./img/ramgy_left.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->ramgy_right = mlx_xpm_file_to_image(par->mlx, \
			"./img/ramgy_right.xpm", &((&par->img)->w), &((&par->img)->h));
	(&par->img)->ramgy = (&par->img)->ramgy_right;
}

static void	ft_draw_tile(char c, t_par *par, int axis_x, int axis_y)
{
	mlx_put_image_to_window(par->mlx, par->win, \
	(&par->img)->grass, 64 * axis_x, 64 * axis_y);
	if (c == '1')
		mlx_put_image_to_window(par->mlx, par->win, \
		(&par->img)->tree, 64 * axis_x, 64 * axis_y);
	else if (c == 'C')
		mlx_put_image_to_window(par->mlx, par->win, \
		(&par->img)->acorn, 64 * axis_x, 64 * axis_y);
}

void	ft_print_map(t_par *par)
{
	char	**map;
	size_t	i;

	map = (par->map);
	i = 0;
	ft_printf("-----------------------------------\n");
	ft_printf("acorn: %d step: %d\n", (&par->chk)->c, (&par->game)->step);
	while (i < (par->height))
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

static void	ft_draw_p_e(t_par *par)
{
	int	e_x;
	int	e_y;
	int	x;
	int	y;

	e_x = (&par->game)->exit_x;
	e_y = (&par->game)->exit_y;
	x = (&par->game)->x;
	y = (&par->game)->y;
	mlx_put_image_to_window(par->mlx, par->win, \
	(&par->img)->rocket, 64 * e_x, 64 * e_y);
	mlx_put_image_to_window(par->mlx, par->win, \
	(&par->img)->ramgy, 64 * x, 64 * y);
}

void	ft_draw_map(t_par *par)
{
	size_t	x;
	size_t	y;

	y = 0;
	mlx_clear_window(par->mlx, par->win);
	while (y < par->height)
	{
		x = 0;
		while (x < par->width)
		{
			ft_draw_tile((par->map)[y][x], par, x, y);
			x++;
		}
		y++;
	}
	ft_draw_p_e(par);
}
