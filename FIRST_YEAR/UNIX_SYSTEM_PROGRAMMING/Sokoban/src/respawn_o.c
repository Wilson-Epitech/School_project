/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** respawn_O
*/

#include "../include/lib.h"

int respawn_o(GAME_T *ALL)
{
    for (int p = 0; ALL->array.array_O[p] != NULL; p++) {
        for (int m = 0; ALL->array.array_O[p][m] != '\0'; m++) {
            if (ALL->array.array_O[p][m] == 'O'
            && ALL->array.array[p][m] == ' ') {
                ALL->array.array[p][m] = 'O';
            }
        }
    }
    return 0;
}
