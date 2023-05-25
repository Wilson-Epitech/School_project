/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** struct
*/

#include "lib.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct ARRAY_STRUCT {
        char *buff;
        int **array;
        char **map;
        int r;
        int s;
        int i;
        int nb_line;
        int width;
        int width_line;
        int left_pos;
        int top_pos;
        int top_left_pos;
        int min_value;
        int nb_max;
        int pos_r_max;
        int pos_s_max;
    } ARRAY_STRUCT_T;

    typedef struct BSQ {
        ARRAY_STRUCT_T array;
    } BSQ_T;

#endif /* !STRUCT_H_ */
