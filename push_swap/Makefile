CC			= 	cc

CFLAGS		= 	-Wall -Wextra -Werror

MANDATORY	= 	srcs/main.c \

BONUS		= 	srcs/bonus/checker_bonus.c \

SRCS		=	srcs/ft_free.c \
				srcs/init_stack.c \
				srcs/ft_node.c \
				srcs/ft_atoi.c \
				srcs/insert_num.c \
				srcs/set_idx.c \
				srcs/cmd/ft_push.c \
				srcs/cmd/ft_swap.c \
				srcs/cmd/ft_rotate.c \
				srcs/cmd/ft_rev.c \
				srcs/ft_command.c \
				srcs/is_sorted.c \
				srcs/push_swap.c \
				srcs/ft_sort.c \
				srcs/a_to_b.c \
				srcs/b_to_a.c \
				srcs/print_err.c \

SRCS_BONUS	= 	srcs/bonus/get_next_line/get_next_line.c \
			  	srcs/bonus/get_next_line/get_next_line_utils.c \
				srcs/ft_free.c \
				srcs/init_stack.c \
				srcs/ft_node.c \
				srcs/ft_atoi.c \
				srcs/insert_num.c \
				srcs/set_idx.c \
				srcs/cmd/ft_push.c \
				srcs/cmd/ft_swap.c \
				srcs/cmd/ft_rotate.c \
				srcs/cmd/ft_rev.c \
				srcs/ft_command.c \
				srcs/is_sorted.c \
				srcs/print_err.c \

OBJS		= $(MANDATORY:.c=.o) $(SRCS:.c=.o)

OBJS_BONUS	= $(BONUS:.c=.o) $(SRCS_BONUS:.c=.o)

NAME		= push_swap

NAME_BONUS	= checker

all 	: $(NAME)

bonus	: $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
		touch $@

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean re
