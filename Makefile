NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = src/headers/

SRCS =	main.c \
		parsing.c \
		utils.c \
		philo.c \
		philo_actions.c \
		utils2.c \
		forks.c
VPATH = $(SRC_DIR) $(HEADER_DIR) $(OBJ_DIR)

OBJS = $(SRCS:%.c=%.o)
OBJ_PRE = $(addprefix $(OBJ_DIR), $(OBJS))
DEP = $(SRCS:%.c=%.h)
DEP_PRE = $(addprefix $(HEADER_DIR), $(DEP))

# Colors
RESET = \033[0m
GREEN = \033[92m
MAGENTA = \033[95m

all: $(NAME)

run: all
	./philo 5 800 200 200

$(OBJ_DIR)%.o: %.c $(DEP_PRE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_PRE)
	@echo "$(GREEN)----$(MAGENTA)Compiling philosophers..$(GREEN)----$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)-----$(MAGENTA)Philosophers compiled!$(GREEN)-----$(RESET)"

clean:
	@echo "$(GREEN)-----$(MAGENTA) Cleaning project...  $(GREEN)-----$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)------$(MAGENTA)  Project cleaned!  $(GREEN)------$(RESET)"

fclean: clean
	@echo "$(GREEN)-----$(MAGENTA) Removing program...  $(GREEN)-----$(RESET)"
	@rm -rf $(NAME)
	@echo "$(GREEN)------$(MAGENTA)  Program removed!  $(GREEN)------$(RESET)"

debug: CFLAGS+=-g
debug: all

re: fclean all