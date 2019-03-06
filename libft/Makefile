# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bturcott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:29:49 by bturcott          #+#    #+#              #
#    Updated: 2018/11/26 21:50:08 by bturcott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c \
ft_isalpha.c\
ft_bzero.c\
ft_isascii.c\
ft_isalnum.c\
ft_isdigit.c\
ft_isprint.c\
ft_lstadd.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstiter.c\
ft_lstnew.c\
ft_memalloc.c\
ft_lstmap.c\
ft_memccpy.c\
ft_itoa.c\
ft_memchr.c\
ft_memdel.c\
ft_memcmp.c\
ft_memcpy.c\
ft_putchar.c\
ft_memset.c\
ft_putendl.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putstr.c\
ft_memmove.c\
ft_putnbr.c\
ft_putstr_fd.c\
ft_strclr.c\
ft_strcat.c\
ft_strchr.c\
ft_strcmp.c\
ft_putnbr_fd.c\
ft_strdel.c\
ft_strcpy.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strdup.c\
ft_strlen.c\
ft_strlcat.c\
ft_strjoin.c\
ft_strmap.c\
ft_strncat.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strsub.c\
ft_tolower.c\
ft_toupper.c\
ft_strtrim.c\
ft_strsplit.c\

LIB = $(FILES:.c=.o)
all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror  -c $(FILES)
	ar rc $(NAME) $(LIB)

clean:
	rm -rf $(LIB)

fclean: 
	make clean
	rm -rf libft.a

re: fclean all

.PHONY: clean fclean
