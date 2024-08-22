/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** print_array
*/

#include "../../include/solver.h"

int print_char(int **array, MapSize *mapsize, int j, int i)
{
    if (array[i][j] == 9)
        putchar('X');
    if (array[i][j] == 2)
        putchar('o');
    if (array[i][j] == 0 || array[i][j] == 5)
        putchar('*');

}

int print_array_solver(int **array, MapSize *mapsize)
{
    int i, j;
    array[mapsize->height - 1][mapsize->width - 1] = 2;
    for (i = 0; i < mapsize->height; i++) {
        for (j = 0; j < mapsize->width; j++) {
            print_char(array, mapsize, j, i);
        }
        if (i < mapsize->height - 1) {
            printf("\n");
        }
    }
    return 0;
}
