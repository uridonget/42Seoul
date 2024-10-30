/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:51 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/22 12:05:23 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS 2

typedef struct s_img
{
	int				w;
	int				h;
	void			*grass;
	void			*acorn;
	void			*rocket;
	void			*ramgy;
	void			*ramgy_left;
	void			*ramgy_right;
	void			*tree;
}	t_img;

typedef struct s_game
{
	int		step;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
}	t_game;

typedef struct s_chk
{
	int		p;
	int		e;
	int		c;
}	t_chk;

typedef struct s_par
{
	char			*file_name;
	t_img			img;
	t_game			game;
	t_chk			chk;
	char			**map;
	size_t			height;
	size_t			width;
	void			*mlx;
	void			*win;
}	t_par;

typedef struct s_stack
{
	int				x;
	int				y;
	struct s_stack	*next;
}	t_stack;

// main.c : main함수, init함수, 탈출용 함수.
int		ft_free_map(char ***map);
int		ft_exit(t_par *par);
void	ft_print_map(t_par *par);

// ft_check_file.c : map 파일의 이름을 확인.
int		ft_check_file(char *file_name);

// ft_read_map.c : 맵 읽어서 height 구하기.
int		ft_read_map(t_par *par);

// ft_make_map.c : 맵 만들기
int		ft_make_map(t_par *par);

// ft_check_map.c : 사각형 검사. 태두리 검사.
int		ft_check_map(t_par *par);

// ft_check_valid.c : 유효한 경로 존재하는지 검사.
int		ft_check_valid(t_par *par);

// ft_bfs_check.c // bfs의 결과물을 확인
int		ft_bfs_check(char **map);
int		ft_free_stack(t_stack **stack);

// ft_draw_map.c : 그림 그리기
void	ft_set_img(t_par *par);
void	ft_print_map(t_par *par);
void	ft_draw_map(t_par *par);

// ft_key_press.c
int		ft_key_press(int keycode, t_par *par);

// ft_err_print.c
int		ft_err_print(char *str);

#endif
