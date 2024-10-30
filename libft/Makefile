# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:49:09 by haejeong          #+#    #+#              #
#    Updated: 2023/10/21 15:18:34 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		  = cc
CFLAGS	  = -Wall -Wextra -Werror
AR		  = ar
ARFLAGS	  = rcs
SRCS	  = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SRCS_BONUS = ft_lstadd_back_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstiter_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstnew_bonus.c \
			 ft_lstmap_bonus.c \
			 ft_lstsize_bonus.c \

OBJS	   = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	CUR_OBJS = $(OBJS) $(OBJS_BONUS)
else
	CUR_OBJS = $(OBJS)
endif

NAME = libft.a

all : $(NAME)

$(NAME) : $(CUR_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(CUR_OBJS)

bonus :
	make WITH_BONUS=1 all

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
