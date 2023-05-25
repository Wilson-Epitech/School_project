##
## EPITECH PROJECT, 2023
## B-CPE-200-PAR-2-1-dante-wilson.bordichon
## File description:
## Makefile
##

SRC =	src/solver.c								\
	src/error_handling.c						\
	src/my_strcmp_custom.c						\
	src/invalid_content_buff.c					\
	src/open_file.c								\
	src/set_start_end_maze.c					\
	src/map_dimensions.c						\
	src/replace_char.c							\
	src/print_array.c							\
	src/free_array.c							\
	src/algo_solv_loop.c						\

OBJ =	$(SRC:.c=.o)

CFLAGS = -g

NAME =	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
