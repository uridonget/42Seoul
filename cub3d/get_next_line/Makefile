# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:46:00 by sangyhan          #+#    #+#              #
#    Updated: 2024/05/11 17:14:23 by sangyhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a
HEADER_DIR	= .
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address
AFLAGS		= rcu
RM			= rm -f
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

%.o : %.c
	cc -I $(HEADER_DIR) $(CFLAGS) -c $?

$(NAME) : $(OBJS)
	ar $(AFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
