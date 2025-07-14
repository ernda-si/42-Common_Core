NAME 	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3 -pthread

SRC		= main.c \
		  initiators.c \
		  creating_threads.c \
		  monitor.c \
		  philo_routine.c \
		  libft_utils.c \
		  utils.c

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
