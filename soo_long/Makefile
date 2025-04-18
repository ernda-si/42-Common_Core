# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 23:47:16 by kali              #+#    #+#              #
#    Updated: 2025/04/16 18:24:51 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =	so_long.c map_checker.c player_update.c read_map.c init.c \
		movements.c end_game.c put_images.c aux_functions.c ft_split.c \
		get_next_line.c flood_fill.c ft_printf/ft_auxfuncs.c ft_printf/ft_printf.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./minilibx-linux -lmlx -L/usr/lib -I./minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
