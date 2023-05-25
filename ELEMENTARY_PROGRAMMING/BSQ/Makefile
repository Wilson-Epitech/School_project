##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make
##

CC      =       gcc
CCFLAGS =       -Wextra -Wall -Werror
CFLAGS  =		-g

SRC     =       main.c									\
				src/init_struct.c						\
				src/init_generator.c					\
				src/error_handling_generator.c			\
				src/map_generator.c						\
				src/count.c								\
				src/print_array.c						\
				src/print_buff.c						\
				src/replace.c							\
				src/find_bsq.c							\
				src/find_max_min_nb.c					\
				src/error_handling.c					\
				src/lib/my_putchar.c					\
				src/lib/my_put_nbr.c					\
				src/lib/my_putstr.c						\
				src/lib/my_strlen.c						\
				src/lib/my_getnbr.c						\
				src/lib/my_str_to_word_array.c			\

OBJ     =       $(SRC:.c=.o)

NAME    =       bsq

all     :       $(NAME)

$(NAME) :       $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CCFLAGS) -g3

clean   :
	$(RM)   $(OBJ)
	$(RM) *~
	cd src && $(RM) *~
	cd src/lib && $(RM) *~
	cd includes && $(RM) *~
fclean  :       clean
	$(RM) $(NAME)

re      :       fclean all
