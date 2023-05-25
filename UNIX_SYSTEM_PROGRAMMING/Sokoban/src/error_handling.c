/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** error_handling
*/

#include "../include/lib.h"

int error_handling(GAME_T *ALL)
{
    int count_O = 0; int count_P = 0; int count_X = 0;

    for (int i = 0; ALL->array.buff[i] != '\0'; i++) {
        if (ALL->array.buff[i] == 'O') {
            count_O++;
        }
        if (ALL->array.buff[i] == 'P') {
            count_P++;
        }
        if (ALL->array.buff[i] == 'X') {
            count_X++;
        }
        if (ALL->array.buff[i] != 'P' && ALL->array.buff[i] != 'O'
        && ALL->array.buff[i] != 'X' && ALL->array.buff[i] != '#'
        && ALL->array.buff[i] != '\n' && ALL->array.buff[i] != ' ') {
            exit(84);
        }
    }
    error_handling_2(count_O, count_P, count_X);
    return 0;
}

int error_handling_2(int count_O, int count_P, int count_X)
{
    if (count_X != count_O) {
        exit(84);
    }
    if (count_P != 1) {
        exit(84);
    }
    return 0;
}

int error_loop(GAME_T *ALL)
{
    error_handling(ALL);
    return 0;
}
