NAME = fdf
FILES2 = main.c libx.c read_from_the_file.c ft_atoi_base.c stash.c draw_the_line.c rotation.c color.c threed.c

LIB = $(FILES2:.c=.o)
all : compile

compile:
	make -C libft/libft
	gcc -c -I./includes $(FILES2) libft/get_next_line.c
	gcc -o fdf -I /usr/local/include -g -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror $(LIB) get_next_line.o libft/libft/libft.a 
clean:
	rm -rf $(LIB)
	make clean -C libft/libft
fclean:
	rm -rf $(LIB)
	rm fdf
	make fclean -C libft/libft
re: fclean all
.PHONY: clean re fclean