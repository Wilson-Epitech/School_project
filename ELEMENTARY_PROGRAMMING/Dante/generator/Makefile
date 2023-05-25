##
## EPITECH PROJECT, 2023
## B-CPE-200-PAR-2-1-dante-wilson.bordichon
## File description:
## Makefile
##

SRC =	generator.c									\
		src/error_handling.c						\
		src/one_line.c 								\
		src/check_generator.c						\
		src/gen_maps.c								\
		src/init_all.c 								\
		src/check_surroundings.c 					\
		src/attribute_new_cases.c 					\
		src/is_bloqued.c 							\
		src/gen_random_stars.c 						\
		../lib/my_strlen.c 							\
		../lib/word_array_delimiter.c 				\
		../lib/word_array_delimiter2.c 				\
		../lib/print_free_array.c 					\

OBJ =	$(SRC:.c=.o)

CFLAGS = -g


NAME =	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
