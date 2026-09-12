NAME = fdf
FILES2 = main.c libx.c read_from_the_file.c ft_atoi_base.c stash.c draw_the_line.c rotation.c color.c threed.c

LIB = $(FILES2:.c=.o)
all : compile

compile:
	$(MAKE) -C libft/libft
	$(CC) -c -I./includes -I includes/X11/include $(FILES2) libft/get_next_line.c
	$(CC) -o $(NAME) -I includes/X11/include -g -L includes/X11/lib  -lX11 -lXext -lmlx -framework AppKit  $(LIB)  get_next_line.o libft/libft/libft.a
clean:
	rm -f $(LIB) get_next_line.o
	$(MAKE) clean -C libft/libft
fclean:
	rm -f $(LIB) get_next_line.o
	rm -f fdf
	$(MAKE) fclean -C libft/libft
re: fclean all
.PHONY: clean re fclean
