# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 16:39:18 by ernda-si          #+#    #+#              #
#    Updated: 2025/10/10 17:06:51 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Replacer.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = replacer

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all