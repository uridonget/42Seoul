# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:46:00 by sangyhan          #+#    #+#              #
#    Updated: 2024/05/12 13:10:53 by sangyhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
HEADER_DIR	= .
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address
AFLAGS		= rcu
RM			= rm -f
SRCS		= ft_atoi.c ft_calloc.c ft_memset.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_putstr_fd.c\
				ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strtrim.c \
				ft_substr.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_strcmp.c \
				ft_itoa.c
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
