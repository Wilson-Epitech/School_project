/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** find_bsq
*/

#include "../includes/lib.h"

int compare_values(BSQ_T *ALL, int x, int y)
{
    if (ALL->array.top_pos < ALL->array.left_pos) {
        ALL->array.min_value = ALL->array.top_pos;
    } else {
        ALL->array.min_value = ALL->array.left_pos;
    }
    if (ALL->array.top_left_pos < ALL->array.min_value) {
        ALL->array.min_value = ALL->array.top_left_pos;
    }
    if (ALL->array.array[x][y] == 1) {
        ALL->array.array[x][y] = ALL->array.array[x][y] + ALL->array.min_value;
    }
}

int find_bsq(BSQ_T *ALL)
{
    int x = 1;
    int y = 1;

    for (int x = 1; x < ALL->array.nb_line; x++) {
        for (int y = 1; y < ALL->array.width_line + 1; y++) {
            ALL->array.left_pos = ALL->array.array[x][y - 1];
            ALL->array.top_pos = ALL->array.array[x - 1][y];
            ALL->array.top_left_pos = ALL->array.array[x - 1][y - 1];
            compare_values(ALL, x, y);
        }
    }
    return 0;
}
