# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:24:29 by haejeong          #+#    #+#              #
#    Updated: 2023/11/07 11:41:12 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS 	= rcs
SRCS		= ./ft_printf.c \
			  ./ft_utils_1.c \
			  ./ft_utils_2.c \
			  ./ft_utils_3.c \

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
