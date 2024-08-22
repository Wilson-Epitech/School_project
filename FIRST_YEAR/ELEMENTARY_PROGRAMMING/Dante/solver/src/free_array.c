/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** free_array
*/

#include "../../include/solver.h"

int free_array_solver(int **array, MapSize *mapsize)
{
    for (int i = 0; i < mapsize->height; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
