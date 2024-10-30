# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:29:32 by haejeong          #+#    #+#              #
#    Updated: 2024/01/22 13:57:49 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
SRCS		= ft_split.c \
			  ft_strjoin.c \
			  ft_strncmp.c \
			  ft_strlen.c \
			  ft_calloc.c \
			  ft_bzero.c \
			  ft_memset.c \

OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

all	: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
