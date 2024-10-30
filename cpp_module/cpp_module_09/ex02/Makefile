# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 10:20:27 by haejeong          #+#    #+#              #
#    Updated: 2024/06/13 18:00:18 by jeonghaecha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = PmergeMe

CXX		 = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

SRCS	 = $(wildcard *.cpp)

INCS	 = $(wildcard *.hpp)

OBJS	 = $(SRCS:.cpp=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCS)
	$(CXX) -c $< -o $@

clean 	:
	rm -rf $(OBJS)

fclean  : clean
	rm -rf $(NAME)

re		: fclean all

.PHONY : all clean fclean re
