# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 16:24:54 by ernda-si          #+#    #+#              #
#    Updated: 2025/04/07 18:55:21 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all