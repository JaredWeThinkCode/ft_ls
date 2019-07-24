# *************************************************************************** #
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

NAME = libft_ls.a

SRC = libft/ft_memccpy.c libft/ft_putnbr.c libft/ft_striter.c libft/ft_strnstr.c libft/ft_memchr.c \
	  libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_strrchr.c libft/ft_memcmp.c \
	  libft/ft_putstr.c libft/ft_strjoin.c libft/ft_strrev.c libft/ft_atoi.c libft/ft_memcpy.c libft/ft_putstr_fd.c \
	  libft/ft_strlcat.c libft/ft_strsplit.c libft/ft_bzero.c libft/ft_memdel.c libft/ft_capitalize.c \
	  libft/ft_strcat.c libft/ft_strlen.c libft/ft_strstr.c libft/ft_isalnum.c libft/ft_memmove.c libft/ft_strchr.c \
	  libft/ft_strmap.c libft/ft_strsub.c libft/ft_isalpha.c libft/ft_memset.c libft/ft_islower.c libft/ft_isupper.c \
	  libft/ft_strclr.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_isascii.c libft/ft_nbrlen.c libft/ft_strcmp.c \
	  libft/ft_strncat.c libft/ft_tolower.c libft/ft_isdigit.c libft/ft_putchar.c libft/ft_isspace.c \
	  libft/ft_strcpy.c libft/ft_strncmp.c libft/ft_toupper.c libft/ft_isprint.c libft/ft_putchar_fd.c \
	  libft/ft_strdel.c libft/ft_strncpy.c libft/ft_itoa.c libft/ft_putendl.c libft/ft_strdup.c \
	  libft/ft_strnequ.c libft/ft_memalloc.c libft/ft_putendl_fd.c libft/ft_strequ.c libft/ft_strnew.c \
	  libft/ft_lstnew.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
	  ft_ls.c ft_flag_a.c ft_flag_init.c ft_flag_l.c ft_flag_lr.c ft_flag_t.c ft_flag_ur.c ft_input.c ft_printf.c ft_sort.c

OBJ = $(patsubst %.c, %.o, $(SRC)) 

INCL = ft_ls.h

TEST = -Wall -Werror -Wextra

PROG = ft_ls

all: $(NAME)

$(NAME): $(OBJ)
	ar rv $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)
	gcc -o $(PROG) $(NAME)

%.o: %.c
	gcc -c $(TEST) -o $@ $<

norm:
	norminette

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(PROG) libft/libft.a

re: fclean all

.PHONY: re clean all fclean
