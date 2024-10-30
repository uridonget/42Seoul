# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 10:20:27 by haejeong          #+#    #+#              #
#    Updated: 2024/04/17 15:34:34 by haejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME	 = Brainz

SRCS	 = $(wildcard *.cpp)

INCS	 = $(wildcard *.hpp)

OBJS	 = $(SRCS:.cpp=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean 	:
	rm -rf $(OBJS)

fclean  : clean
	rm -rf $(NAME)

re		:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
