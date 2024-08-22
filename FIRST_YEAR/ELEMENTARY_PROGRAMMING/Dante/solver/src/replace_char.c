/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** replace_char
*/

#include "../../include/solver.h"

void replace_char2(ReplaceParams params)
{
    if (params.buff[params.i] == '*') {
        params.array[params.r][params.s] = 0;
    }
    if (params.buff[params.i] == 'X') {
        params.array[params.r][params.s] = 9;
    }
}

int **replace_char(int **array, char *buff, MapSize *mapsize)
{
    int i = 0;
    for (int r = 0; r < mapsize->height; r++) {
        array[r] = malloc(sizeof(int) * mapsize->width);
        for (int s = 0; s < mapsize->width + 1; s++) {
            ReplaceParams params = {buff, array, r, s, i};
            replace_char2(params);
            i++;
        }
    }
    return array;
}
