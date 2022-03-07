NAME = pipex
SOURCE = src/pipex.c src/path_management.c src/main_utils.c src/struct_manager.c src/openers.c src/executer.c
OBJS = $(SOURCE:.c=.o)
LIBFT = 												./includes/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(LIBFT):
	make -C ./includes/libft

.PHONY: clean fclean re bonus all

clean:
	make clean -C ./includes/libft
	rm -rf $(OBJS)
fclean: clean
	make fclean -C ./includes/libft
	rm -rf $(NAME)
re: fclean all