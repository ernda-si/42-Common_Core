# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 12:26:48 by ernda-si          #+#    #+#              #
#    Updated: 2024/04/15 16:35:37 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
	ft_memcmp.c ft_memset.c ft_strchr.c ft_strlcat.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c

OBJ = $(SRC.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re