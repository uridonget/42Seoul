/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:27:40 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/13 17:34:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_move_down(t_par *par)
{
	int	x;
	int	y;

	x = (&par->game)->x;
	y = (&par->game)->y;
	if ((x == (&par->game)->exit_x) && (y + 1 == (&par->game)->exit_y))
	{
		if ((&par->chk)->c == 0)
			ft_exit(par);
	}
	if ((par->map)[y + 1][x] == '1')
		return ;
	if ((par->map)[y + 1][x] == 'C')
		(&par->chk)->c--;
	(&par->game)->y++;
	(&par->game)->step++;
	(par->map)[y][x] = '0';
	(par->map)[y + 1][x] = 'P';
}

static void	ft_move_up(t_par *par)
{
	int	x;
	int	y;

	x = (&par->game)->x;
	y = (&par->game)->y;
	if ((x == (&par->game)->exit_x) && (y - 1 == (&par->game)->exit_y))
	{
		if ((&par->chk)->c == 0)
			ft_exit(par);
	}
	if ((par->map)[y - 1][x] == '1')
		return ;
	if ((par->map)[y - 1][x] == 'C')
		(&par->chk)->c--;
	(&par->game)->y--;
	(&par->game)->step++;
	(par->map)[y][x] = '0';
	(par->map)[y - 1][x] = 'P';
}

static void	ft_move_right(t_par *par)
{
	int	x;
	int	y;

	(&par->img)->ramgy = (&par->img)->ramgy_left;
	x = (&par->game)->x;
	y = (&par->game)->y;
	if ((x - 1 == (&par->game)->exit_x) && (y == (&par->game)->exit_y))
	{
		if ((&par->chk)->c == 0)
			ft_exit(par);
	}
	if ((par->map)[y][x - 1] == '1')
		return ;
	if ((par->map)[y][x - 1] == 'C')
		(&par->chk)->c--;
	(&par->game)->x--;
	(&par->game)->step++;
	(par->map)[y][x] = '0';
	(par->map)[y][x - 1] = 'P';
}

static void	ft_move_left(t_par *par)
{
	int	x;
	int	y;

	(&par->img)->ramgy = (&par->img)->ramgy_right;
	x = (&par->game)->x;
	y = (&par->game)->y;
	if ((x + 1 == (&par->game)->exit_x) && (y == (&par->game)->exit_y))
	{
		if ((&par->chk)->c == 0)
			ft_exit(par);
	}
	if ((par->map)[y][x + 1] == '1')
		return ;
	if ((par->map)[y][x + 1] == 'C')
		(&par->chk)->c--;
	(&par->game)->x++;
	(&par->game)->step++;
	(par->map)[y][x] = '0';
	(par->map)[y][x + 1] = 'P';
}

int	ft_key_press(int keycode, t_par *par)
{
	if (keycode == 13)
		ft_move_up(par);
	else if (keycode == 1)
		ft_move_down(par);
	else if (keycode == 2)
		ft_move_left(par);
	else if (keycode == 0)
		ft_move_right(par);
	else if (keycode == 53)
		ft_exit(par);
	ft_print_map(par);
	ft_draw_map(par);
	return (0);
}
