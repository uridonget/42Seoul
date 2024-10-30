/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:21:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 17:20:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../../minilibx_opengl/mlx.h"
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"

# define KEY_ESC 53
# define KEY_SHIFT 257
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_window
{
	int		width;
	int		height;
	void	*image;
	void	*image_address;
	int		image_size;
}	t_window;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	int			endian;
	int			bit;
	t_window	minimap;
	t_window	display;
}	t_mlx;

typedef struct s_mapLst
{
	char			*line;
	struct s_mapLst	*prev;
	struct s_mapLst	*next;
}	t_mapLst;

typedef struct s_map
{
	t_mapLst	*lst;
	size_t		height;
	size_t		width;
	char		**map;
}	t_map;

typedef struct s_ray
{
	double	speed;
	double	pos_x;
	double	pos_y;
	double	direction;
	double	delta_front_x;
	double	delta_front_y;
	double	delta_side_x;
	double	delta_side_y;
}	t_ray;

typedef struct s_move
{
	int	front;
	int	back;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
}	t_move;

typedef struct s_texture_file
{
	char	*path;
	void	*image;
	void	*image_addr;
	int		bit;
	int		endian;
	int		height;
	int		width;
	int		image_size;
}	t_texture_file;

typedef struct s_texture
{
	t_texture_file	north;
	t_texture_file	south;
	t_texture_file	west;
	t_texture_file	east;
	int				floor;
	int				ceiling;
}	t_texture;

typedef struct s_museum
{
	t_map		map;
	t_texture	texture;
	t_mlx		mlx;
	t_ray		ray;
	t_move		move;
}	t_museum;

typedef struct s_int_dot
{
	int	x;
	int	y;
}	t_int_dot;

typedef struct s_double_dot
{
	double	x;
	double	y;
}	t_double_dot;

void		init_museum(t_museum *mu, int ac, char **av);

int			open_map_file(char *fileName, t_museum *mu);

void		set_north_texture(char *trim, int *cnt, t_museum *mu);
void		set_south_texture(char *trim, int *cnt, t_museum *mu);
void		set_east_texture(char *trim, int *cnt, t_museum *mu);
void		set_west_texture(char *trim, int *cnt, t_museum *mu);

void		set_floor(char *trim, int *cnt, t_museum *mu);
void		set_ceiling(char *trim, int *cnt, t_museum *mu);

t_mapLst	*map_lst_new(char *content);
void		map_lst_add_back(t_mapLst **lst, t_mapLst *new);

void		make_map(t_museum *mu);

void		make_base(t_museum *mu);

int			check_surround(char **map, t_museum *mu);

int			check_museum(t_museum *mu);

int			key_press(int keycode, t_museum *mu);
int			key_release(int keycode, t_museum *mu);
int			close_mlx(t_museum *mu);

void		init_texture(t_museum *mu);

void		init_mlx(t_museum *mu);

void		draw_minimap(t_museum *mu);

int			main_loop(t_museum *mu);
void		update_delta(t_ray *ray);

double		find_vertical(t_museum *mu, double direction, double *distance);
double		find_horizontal(t_museum *mu, double direction, double *distance);

void		raycast(t_museum *minimap, double direction, int displayIndex);
void		render(t_museum *map);

void		free_strs(char **strs);
size_t		ft_strslen(char **strs);
void		ft_error(char *errMsg);

#endif
