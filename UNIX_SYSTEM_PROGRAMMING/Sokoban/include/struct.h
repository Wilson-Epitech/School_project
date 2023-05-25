/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** struct
*/

#include "lib.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct PLAYER_POS {
        int x;
        int y;
    } PLAYER_POS_T;

    typedef struct ARRAY_STRUCT {
        char *buff;
        char **array;
        char **array_O;
    } ARRAY_STRUCT_T;

    typedef struct GAME {
        ARRAY_STRUCT_T array;
        PLAYER_POS_T player_pos_values;
    } GAME_T;

#endif /* !STRUCT_H_ */
