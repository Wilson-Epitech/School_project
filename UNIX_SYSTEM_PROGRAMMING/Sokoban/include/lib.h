/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** func
*/

#ifndef FUNC_H_
    #define FUNC_H_
    #include <ncurses.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include "struct.h"

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void keys(GAME_T *ALL, int ch);
char **my_str_to_word_array(char const *str);
int *read_map(GAME_T * ALL, int ac, char **av);
void init(GAME_T *ALL, int ac, char **av);
void key_up(GAME_T *ALL, PLAYER_POS_T *pos);
void key_down(GAME_T *ALL, PLAYER_POS_T *pos);
void key_left(GAME_T *ALL, PLAYER_POS_T *pos);
void key_right(GAME_T *ALL, PLAYER_POS_T *pos);
int error_loop(GAME_T *ALL);
int error_handling_2(int count_O, int count_P, int count_X);
int respawn_o(GAME_T *ALL);
#endif /* FUNC_H_ */
