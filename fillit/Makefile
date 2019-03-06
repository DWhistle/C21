NAME = fillit
INCL = fillit.c appendix.c figure_reset.c figure_offset.c figure_standartization.c figure_validation.c fill_map.c get_input.c scale_adjustment.c utility.c
OBJ = $(INCL:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c $(INCL)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
