# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:31:53 by haejeong          #+#    #+#              #
#    Updated: 2024/05/14 15:18:44 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY				= 	cub3D
BONUS					=	bonus
BONUS_NAME				=	cub3D_bonus
CC						= 	cc -Wall -Wextra -Werror #-fsanitize=address
CFLAGS					= 	
MLX		 				= 	minilibx_opengl/libmlx.a
GNL						= 	get_next_line/libgnl.a
LIBFT					= 	libft/libft.a
MLX_INCLUDE				=	-L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit
GNL_INCLUDE				=	-L./get_next_line -lgnl
LIBFT_INCLUDE			=	-L./libft -lft
MANDATORY_SRCS_DIR		= 	mandatory/srcs/
MANDATORY_SRC_LIST 		= 	angle_event.c check_museum.c check_surround.c draw_minimap.c init_mlx.c init_museum.c init_texture.c \
							key_event.c linked_map_list.c main_loop.c main.c make_base.c make_map.c open_map_file.c raycast_hor.c \
							raycast_ver.c raycast.c render.c set_floor_ceiling.c set_texture.c util.c
MANDATORY_SRCS	 		=	$(addprefix $(MANDATORY_SRCS_DIR), $(MANDATORY_SRC_LIST))
MANDATORY_INCS	 		=	mandatory/include
MANDATORY_OBJS	 		=	$(MANDATORY_SRCS:.c=.o)
BONUS_SRCS_DIR			= 	bonus/srcs/
BONUS_SRC_LIST	 		= 	angle_event_bonus.c check_museum_bonus.c check_surround_bonus.c draw_minimap_bonus.c init_mlx_bonus.c \
							init_museum_bonus.c init_texture_bonus.c key_event_bonus.c linked_map_list_bonus.c main_loop_bonus.c \
							main_bonus.c make_base_bonus.c make_map_bonus.c open_map_file_bonus.c raycast_hor_bonus.c \
							raycast_ver_bonus.c raycast_bonus.c render_bonus.c set_floor_ceiling_bonus.c set_texture_bonus.c util_bonus.c \
							door_bonus.c set_sprite_bonus.c sprite_image_to_window_bonus.c raycast_util_bonus.c close_mlx_bonus.c
BONUS_SRCS	 			=	$(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRC_LIST))
BONUS_INCS	 			=	bonus/include
BONUS_OBJS	 			=	$(BONUS_SRCS:.c=.o)

all	: $(MANDATORY)

$(MANDATORY) : $(MANDATORY_OBJS) $(MLX) $(GNL) $(LIBFT)
	$(CC) $(MANDATORY_OBJS) -o $(MANDATORY) $(MLX_INCLUDE) $(LIBFT_INCLUDE) $(GNL_INCLUDE)

$(BONUS) : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(MLX) $(GNL) $(LIBFT)
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME) $(MLX_INCLUDE) $(LIBFT_INCLUDE) $(GNL_INCLUDE)

$(MLX) :
	cd ./minilibx_opengl ; make all

$(GNL) : 
	cd ./get_next_line ; make all

$(LIBFT) : 
	cd ./libft ; make all

%.o : %.c $(MANDATORY_SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean 	:
	rm -rf $(MANDATORY_OBJS)
	rm -rf $(BONUS_OBJS)
	cd ./minilibx_opengl ; make clean
	cd ./get_next_line ; make clean
	cd ./libft ; make clean

fclean  : clean
	rm -rf $(MANDATORY)
	rm -rf $(BONUS_NAME)
	cd ./minilibx_opengl ; make clean
	cd ./get_next_line ; make fclean
	cd ./libft ; make fclean

re		: fclean all

.PHONY : all clean fclean re
