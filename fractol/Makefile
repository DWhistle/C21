NAME = fractol
FILES2 = main.c stash.c buttons.c terrain.c terrain_drawing.c opencl.c terrain2.c terrain3.c

LIB =  $(FILES2:.c=.o)
all : compile

compile:
	make -C libft/libft
	gcc -c -I./includes $(FILES2)
	gcc -o $(NAME) -I ./includes/X11/include -g -L ./includes/X11/lib  -lX11 -lXext -lmlx -framework OpenGL -framework AppKit -framework OpenCL $(LIB) libft/libft/libft.a
clean:
	rm -rf $(LIB)
	make clean -C libft/libft
fclean:
	make clean
	rm -rf fractol
	make fclean -C libft/libft 
re: fclean all
.PHONY: clean re fclean
