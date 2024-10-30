CC			= cc
AR			= ar

CFLAGS		= -Wall -Werror -Wextra
ARFLAGS		= -rcs
MLX_FLAGS 	= -L ./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		= srcs/main.c \
			  srcs/ft_check_file.c \
			  srcs/ft_read_map.c \
			  srcs/ft_make_map.c \
			  srcs/ft_check_map.c \
			  srcs/ft_check_valid.c \
			  srcs/ft_bfs_check.c \
			  srcs/ft_draw_map.c \
			  srcs/ft_key_press.c \
			  srcs/ft_err_print.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \

PRINTF_A	= ./printf/libftprintf.a

OBJS		= $(SRCS:.c=.o)

NAME 		= so_long

all : $(NAME)

$(NAME) : $(OBJS) libftprintf
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(PRINTF_A) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
libftprintf:
	$(MAKE) -C ./printf

clean:
	$(MAKE) -C ./printf clean;
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C ./printf fclean;
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re