##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	main.c								\
	src/parsing/parsing_input.c 			\
	src/parsing/check_line_type1.c 			\
	src/parsing/check_line_type2.c 			\
	src/parsing/parse_start_line.c 			\
	src/parsing/parse_end_line.c 			\
	src/parsing/parse_rooms_and_tunnels.c	\
	src/parsing/parsing_error_handling.c	\
	src/algo/matrix.c						\
	src/algo/stock_positions.c 				\
	src/algo/print_ants_moves.c 			\
	src/error_handling.c 					\
	src/algo/rename_rooms.c					\
	lib/my_putchar.c						\
	lib/my_putstr.c							\
	lib/my_strlen.c             			\
	lib/my_put_nbr.c 						\
	lib/my_getnbr.c 						\
	lib/my_strcmp.c 						\
	lib/my_strncmp.c 						\
	lib/word_array_delimiter.c 				\
	lib/word_array_delimiter2.c				\
	lib/print_free_array.c 					\
	lib/my_strdup.c

OBJ =	$(SRC:.c=.o)

CPPFLAGS = -iquote./includes

CFLAGS = -Wall -Wextra -g3

NAME =	lem_in

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
