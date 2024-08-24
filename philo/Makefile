SRCS	=	main.c

OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
HDRS    = inc/philo.h
NAME    = philo
RM  = rm -rf
FLAGS   = -Wall -Wextra -Werror

all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME):	$(OBJS)
	cc ${FLAGS} ${OBJS} -o ${NAME}

re:		clean fclean all

clean:
		@$(RM) $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@$(RM) $(OBJS) $(NAME)

.PHONY:
		all clean fclean re bonus