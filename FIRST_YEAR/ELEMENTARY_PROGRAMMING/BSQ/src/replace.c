/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** replace
*/

#include "../includes/lib.h"

int replace_bsq(BSQ_T *ALL)
{
    int pos_r_min = ALL->array.pos_r_max - ALL->array.nb_max + 2;
    int pos_s_min = ALL->array.pos_s_max - ALL->array.nb_max + 1;

    for (int r = pos_r_min; r <= ALL->array.pos_r_max + 1; r++) {
        for (int s = pos_s_min; s <= ALL->array.pos_s_max; s++) {
            ALL->array.map[r][s] = 'x';
        }
    }
    return 0;
}

int replace_bsq_generator(BSQ_T *ALL)
{
    int pos_r_min = ALL->array.pos_r_max - ALL->array.nb_max + 1;
    int pos_s_min = ALL->array.pos_s_max - ALL->array.nb_max + 1;

    for (int r = pos_r_min; r <= ALL->array.pos_r_max; r++) {
        for (int s = pos_s_min; s <= ALL->array.pos_s_max; s++) {
            ALL->array.map[r][s] = 'x';
        }
    }
    return 0;
}

void replace_char2(BSQ_T *ALL)
{
    if (ALL->array.buff[ALL->array.i] == '.') {
        ALL->array.array[ALL->array.r][ALL->array.s] = 1;
    }
    if (ALL->array.buff[ALL->array.i] == 'o') {
        ALL->array.array[ALL->array.r][ALL->array.s] = 0;
    }
}

int replace_char(BSQ_T *ALL)
{
    for (ALL->array.r = 0; ALL->array.r < ALL->array.nb_line; ALL->array.r++) {
        ALL->array.array[ALL->array.r] =
            malloc(sizeof(int) * ALL->array.width_line);
        for (ALL->array.s = 0; ALL->array.s < ALL->array.width_line + 1;
            ALL->array.s++) {
            replace_char2(ALL);
            ALL->array.i++;
        }
    }
    return 0;
}
