/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** find_max_min_nb
*/

#include "../includes/lib.h"

void asign_values_max_nb(BSQ_T *ALL, int r, int s)
{
    if (ALL->array.array[r][s] > ALL->array.nb_max) {
        ALL->array.nb_max = ALL->array.array[r][s];
        ALL->array.pos_r_max = r;
        ALL->array.pos_s_max = s;
    }

}

int find_max_nb(BSQ_T *ALL)
{
    ALL->array.nb_max = ALL->array.array[0][0];
    for (int r = 0; r != ALL->array.nb_line; r++) {
        for (int s = 0; s != ALL->array.width_line; s++) {
            asign_values_max_nb(ALL, r, s);
        }
    }
    return 0;
}

int find_min_nb(BSQ_T *ALL)
{
    int pos_r_min = ALL->array.pos_r_max - ALL->array.nb_max + 1;
    int pos_s_min = ALL->array.pos_s_max - ALL->array.nb_max + 1;

    for (int r = pos_r_min; r <= ALL->array.pos_r_max; r++) {
        for (int s = pos_s_min; s <= ALL->array.pos_s_max; s++) {
            ALL->array.array[r][s] = 8;
        }
    }
    return 0;
}
