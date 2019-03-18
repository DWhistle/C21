NAME = fdf
FILES2 = main.c libx.c read_from_the_file.c ft_atoi_base.c stash.c draw_the_line.c rotation.c color.c threed.c

LIB = $(FILES2:.c=.o)
all : compile

compile:
	make -C libft/libft
	gcc -c -I./includes $(FILES2) libft/get_next_line.c
	gcc -o $(NAME) -I includes/X11/include -g -L includes/X11/lib  -lX11 -lXext -lmlx -framework AppKit  $(LIB)  get_next_line.o libft/libft/libft.a 
clean:
	rm -rf $(LIB)
	make clean -C libft/libft
fclean:
	rm -rf $(LIB)
	rm fdf
	make fclean -C libft/libft
re: fclean all
.PHONY: clean re fclean