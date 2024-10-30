CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= ./mandatory/main.c \
			  ./mandatory/ft_init.c \
			  ./mandatory/open_file.c \
			  ./mandatory/set_path.c \
			  ./mandatory/exec_cmd.c \
			  ./mandatory/free_close.c \

SRCS_BONUS	= ./bonus/main_bonus.c \
			  ./bonus/ft_init_bonus.c \
			  ./bonus/open_file_bonus.c \
			  ./bonus/set_path_bonus.c \
			  ./bonus/free_close_bonus.c \
			  ./bonus/exec_cmd_bonus.c \
			  ./bonus/here_doc_bonus.c \
			  ./bonus/get_next_line/get_next_line.c \
			  ./bonus/get_next_line/get_next_line_utils.c \

LIBFT_A		= libft/libft.a

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME		= pipex

all : LAST_ALL

bonus	: LAST_BONUS

LAST_ALL	: $(OBJS) $(LIBFT_A)
	$(RM) LAST_BONUS
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJS) -o $(NAME)
	touch $@

LAST_BONUS	: $(OBJS_BONUS) $(LIBFT_A)
	$(RM) LAST_ALL
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJS_BONUS) -o $(NAME)
	touch $@

$(LIBFT_A) : ./libft/*.c ./libft/*.h
	$(MAKE) -C ./libft all

clean :
	$(MAKE) -C ./libft clean;
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(MAKE) -C ./libft fclean;
	$(RM) LAST_ALL
	$(RM) LAST_BONUS
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus