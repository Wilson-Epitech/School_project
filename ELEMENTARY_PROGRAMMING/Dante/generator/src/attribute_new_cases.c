/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** gen_map_wall
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/generator.h"
#include <time.h>

void attribute_up_and_down(structure_t *gen)
{
    if (gen->x == gen->length_map - 1 && gen->length_map % 2 != 0) {
        gen->cases[0][0] = gen->x + 1;
        gen->cases[0][1] = gen->y;
    } else {
        gen->cases[0][0] = gen->x + 2;
        gen->cases[0][1] = gen->y;
    }

    if (gen->x == gen->length_map && gen->length_map % 2 != 0) {
        gen->cases[3][0] = gen->x - 1;
        gen->cases[3][1] = gen->y;
    } else {
        gen->cases[3][0] = gen->x - 2;
        gen->cases[3][1] = gen->y;
    }
}

void attribute_left_and_right(structure_t *gen)
{
    if (gen->y == gen->width_map - 1 && gen->width_map % 2 != 0) {
        gen->cases[1][0] = gen->x;
        gen->cases[1][1] = gen->y + 1;
    } else {
        gen->cases[1][0] = gen->x;
        gen->cases[1][1] = gen->y + 2;
    }

    if (gen->y == gen->width_map && gen->width_map % 2 != 0) {
        gen->cases[2][0] = gen->x;
        gen->cases[2][1] = gen->y - 1;
    } else {
        gen->cases[2][0] = gen->x;
        gen->cases[2][1] = gen->y - 2;
    }
}

void attribute_new_cases(structure_t *gen)
{
    attribute_up_and_down(gen);
    attribute_left_and_right(gen);
}
