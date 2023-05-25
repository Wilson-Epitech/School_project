##
## EPITECH PROJECT, 2022
## B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
## File description:
## Makefile
##

CC	=	gcc

CFLAGS  =	-Wextra -Wall

LDFLAFS = -lncurses

SRC	=	src/main.c							\
		src/respawn_o.c						\
		src/error_handling.c				\
		src/keys/keys.c 					\
		src/keys/key_up.c 					\
		src/keys/key_down.c 				\
		src/keys/key_left.c 				\
		src/keys/key_right.c				\
		src/init_struct.c					\
		src/lib/my_strlen.c					\
		src/lib/my_put_nbr.c				\
		src/lib/my_putchar.c				\
		src/lib/my_putstr.c 				\
		src/lib/my_str_to_word_array.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAFS)

clean	:
	rm -f *~
	rm -f *.o
	cd src &&  rm -f *~
	cd src &&  rm -f *.o
	cd src/lib &&  rm -f *~
	cd src/lib &&  rm -f *.o
	cd src/keys &&  rm -f *~
	cd src/keys &&  rm -f *.o

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
