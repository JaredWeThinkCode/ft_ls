# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/31 15:13:34 by jnaidoo           #+#    #+#              #
#    Updated: 2019/06/28 15:30:28 by jnaidoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memccpy.c ft_putnbr.c ft_striter.c ft_strnstr.c ft_memchr.c \
	  ft_putnbr_fd.c ft_striteri.c ft_strrchr.c ft_memcmp.c \
	  ft_putstr.c ft_strjoin.c ft_strrev.c ft_atoi.c ft_memcpy.c ft_putstr_fd.c \
	  ft_strlcat.c ft_strsplit.c ft_bzero.c ft_memdel.c ft_capitalize.c \
	  ft_strcat.c ft_strlen.c ft_strstr.c ft_isalnum.c ft_memmove.c ft_strchr.c \
	  ft_strmap.c ft_strsub.c ft_isalpha.c ft_memset.c ft_islower.c ft_isupper.c \
	  ft_strclr.c ft_strmapi.c ft_strtrim.c ft_isascii.c ft_nbrlen.c ft_strcmp.c \
	  ft_strncat.c ft_tolower.c ft_isdigit.c ft_putchar.c ft_isspace.c \
	  ft_strcpy.c ft_strncmp.c ft_toupper.c ft_isprint.c ft_putchar_fd.c \
	  ft_strdel.c ft_strncpy.c ft_itoa.c ft_putendl.c ft_strdup.c \
	  ft_strnequ.c ft_memalloc.c ft_putendl_fd.c ft_strequ.c ft_strnew.c \
	  ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c

OBJ = $(patsubst %.c, %.o, $(SRC)) 

INCL = libft.h

TEST = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rv $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(TEST) -o $@ $<

norm:
	norminette

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

program: $(NAME) main.c
	gcc -o program main.c $(NAME)
	./program

.PHONY: re clean all fclean test
