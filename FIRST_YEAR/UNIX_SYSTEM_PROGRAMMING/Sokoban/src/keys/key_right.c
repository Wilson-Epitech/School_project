/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** key_right
*/

#include "../../include/lib.h"

void key_right(GAME_T *ALL, PLAYER_POS_T *pos)
{
    if ((ALL->array.array[pos->x][pos->y + 1] == ' ')
    || (ALL->array.array[pos->x][pos->y + 1] == 'O')) {
        ALL->array.array[pos->x][pos->y] = ' ';
        pos->y = pos->y + 1;
        ALL->array.array[pos->x][pos->y] = 'P';
        return;
    }
    if (ALL->array.array[pos->x][pos->y + 1] == 'X'
    && ALL->array.array[pos->x][pos->y + 2] != '#'
    && ALL->array.array[pos->x][pos->y + 2] != 'X') {
        ALL->array.array[pos->x][pos->y] = ' ';
        ALL->array.array[pos->x][pos->y + 1] = 'P';
        ALL->array.array[pos->x][pos->y + 2] = 'X';
        pos->y = pos->y + 1;
        return;
    }
}
