# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 14:54:35 by ernda-si          #+#    #+#              #
#    Updated: 2025/08/28 15:00:49 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread -g -O3 -pthread

SRC		= main.c initializers.c monitor.c helpers.c utils.c \
			threads.c routine.c time.c tasks.c parsing.c

OBJDIR	= obj
OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

RED     = \033[31m
GREEN   = \033[32m
YELLOW	= \033[33m
BLUE    = \033[34m
NC      = \033[0m

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling philo...$(NC)"	
	@echo "$(GREEN)Linking philo...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning objects...$(NC)"
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)Removing executable...$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
