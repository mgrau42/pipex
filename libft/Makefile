# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 11:17:40 by mgrau             #+#    #+#              #
#    Updated: 2020/02/26 22:02:03 by mgrau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_toupper.c ft_strrchr.c ft_strnstr.c ft_tolower.c ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
ft_strchr.c ft_memset.c ft_memmove.c ft_memcpy.c ft_memcmp.c ft_revstrncmp.c\
ft_memchr.c ft_memccpy.c ft_isprint.c ft_isascii.c ft_isalpha.c\
ft_isalnum.c ft_isdigit.c ft_bzero.c ft_atoi.c ft_strdup.c ft_calloc.c\
ft_itoa.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_split.c ft_putchar_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_putstr_fd.c ft_strmapi.c ft_strcpy.c ft_int_order.c ft_intdup.c ft_charcount.c
BSOURCE = ft_lstadd_back.c ft_lstadd_front.c \
ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = $(SOURCE:.c=.o)
BOBJS = ft_lstadd_back.o ft_lstadd_front.o \
ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): OBJS
	ar rcs $(NAME) $(OBJS)
OBJS:
	gcc $(FLAGS) -c $(SOURCE)
bonus: BSOURCE

BSOURCE: BOBJS
	ar rcs $(NAME) $(OBJS) $(BOBJS)
BOBJS:
	gcc $(FLAGS) -c $(SOURCE) $(BSOURCE)

.PHONY: clean

clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
