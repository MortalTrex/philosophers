NAME    = philo

SRCS    = src/main.c\
		  src/utils.c\
		  src/init.c\
		  src/check.c

OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HDRS    = inc/philo.h
FLAGS   = -Wall -Wextra -Werror -pthread

all:    $(NAME)

$(OBJ_DIR)/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(NAME):    $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;31m...philo is ready\033[0m"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:     fclean all

.PHONY: all clean fclean re
