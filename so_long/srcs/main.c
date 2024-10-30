/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:15:42 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/19 12:22:20 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	par_init(t_par *par)
{
	(&par->game)->step = 0;
	if (!(ft_read_map(par)))
		return (0);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, \
			64 * (par->width), 64 * (par->height), "so_long");
	if (!(ft_make_map(par)))
		return (ft_err_print("Error\n"));
	if (!(ft_check_map(par)))
	{
		ft_printf("Error\n");
		ft_exit(par);
	}
	ft_set_img(par);
	ft_print_map(par);
	ft_draw_map(par);
	return (1);
}

int	ft_free_map(char ***map)
{
	int	i;

	i = 0;
	if (*map)
	{
		while (*map && (*map)[i])
		{
			free((*map)[i]);
			(*map)[i] = 0;
			i++;
		}
		free(*map);
		*map = 0;
	}
	return (0);
}

int	ft_exit(t_par *par)
{
	mlx_destroy_window(par->mlx, par->win);
	ft_free_map(&(par->map));
	exit(0);
}

int	main(int ac, char **av)
{
	t_par	par;

	if (ac != 2)
		return (0);
	if (!(ft_check_file(av[1])))
	{
		ft_printf("wrong file_extension\nError\n");
		return (0);
	}
	(&par)->file_name = av[1];
	if (!(par_init(&par)))
	{
		ft_printf("Error\n");
		return (0);
	}
	mlx_hook(par.win, X_EVENT_KEY_PRESS, 0, &ft_key_press, &par);
	mlx_hook(par.win, 17, 0, ft_exit, &par);
	mlx_loop(par.mlx);
	return (0);
}
