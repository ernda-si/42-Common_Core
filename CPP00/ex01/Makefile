# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eve <eve@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 16:37:39 by ernda-si          #+#    #+#              #
#    Updated: 2025/09/30 02:00:37 by eve              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = contact.cpp main.cpp phonebook.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
