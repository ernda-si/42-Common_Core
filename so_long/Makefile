# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 23:47:16 by kali              #+#    #+#              #
#    Updated: 2024/12/13 01:23:36 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Project sources
SRC = 

# Object conversion
OBJ = $(SRC:.c=.o)

# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Name of the program
NAME = 

# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Link X11 and MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
