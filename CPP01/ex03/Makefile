# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eve <eve@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 20:16:31 by eve               #+#    #+#              #
#    Updated: 2025/09/12 18:23:46 by eve              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all