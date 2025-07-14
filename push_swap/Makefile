# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 16:58:06 by ernda-si          #+#    #+#              #
#    Updated: 2025/04/02 12:17:51 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c push_swap_utils.c pushes.c rotates.c im_tired.c \
rrotates.c swaps.c ft_split.c extra_utils.c helper_functions.c utils.c \
parsing.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all