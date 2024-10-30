# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 14:29:32 by haejeong          #+#    #+#              #
#    Updated: 2024/03/26 08:21:57 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
SRCS		= ft_itoa.c \
			  ft_atoi.c \
			  ft_isalpha.c \
			  ft_isalnum.c \
			  ft_isdigit.c \
			  ft_bzero.c \
			  ft_memset.c \
			  ft_calloc.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strdup.c \
			  ft_strjoin.c \
			  ft_strlen.c \
			  ft_strslen.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_substr.c \
			  ft_strlcpy.c \
			  ft_strcat.c \
			  ft_trim.c \

OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

all	: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
