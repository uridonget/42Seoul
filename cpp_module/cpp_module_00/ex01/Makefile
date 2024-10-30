# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 13:08:15 by haejeong          #+#    #+#              #
#    Updated: 2024/04/15 17:16:25 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME	 = phonebook

SRCS	 = ./main.cpp \
		   ./phonebook.cpp \
		   ./contact.cpp \

OBJS	 = $(SRCS:.cpp=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean 	:
	rm -rf $(OBJS)

fclean  : clean
	rm -rf $(NAME)

re		:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
