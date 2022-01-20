NAME = pipex
SOURCE = pipex.c path_management.c main_utils.c struct_manager.c openers.c executer.c
OBJS = $(SOURCE:.c=.o)
LIBFT = 												../libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(LIBFT):
	make -C ../libft

.PHONY: clean fclean re bonus all

clean:
	make clean -C ../libft
	rm -rf $(OBJS)
fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)
re: fclean all