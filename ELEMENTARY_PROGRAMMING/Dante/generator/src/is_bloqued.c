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

void is_bloqued_up_down(structure_t *gen, char **map)
{
    if (gen->cases[0][0] >= 0 && gen->cases[0][0] <= gen->length_map
    && gen->cases[0][1] >= 0 && gen->cases[0][1] <= gen->width_map) {
        gen->possibilities += 1;
        if (map[gen->cases[0][0]][gen->cases[0][1]] == '*')
            gen->bloqued += 1;
    }
    if (gen->cases[1][0] >= 0 && gen->cases[1][0] <= gen->length_map
    && gen->cases[1][1] >= 0 && gen->cases[1][1] <= gen->width_map) {
        gen->possibilities += 1;
        if (map[gen->cases[1][0]][gen->cases[1][1]] == '*')
            gen->bloqued += 1;
    }
}

void is_bloqued_left_right(structure_t *gen, char **map)
{
    if (gen->cases[2][0] >= 0 && gen->cases[2][0] <= gen->length_map
    && gen->cases[2][1] >= 0 && gen->cases[2][1] <= gen->width_map) {
        gen->possibilities += 1;
        if (map[gen->cases[2][0]][gen->cases[2][1]] == '*')
            gen->bloqued += 1;
    }
    if (gen->cases[3][0] >= 0 && gen->cases[3][0] <= gen->length_map
    && gen->cases[3][1] >= 0 && gen->cases[3][1] <= gen->width_map) {
        gen->possibilities += 1;
        if (map[gen->cases[3][0]][gen->cases[3][1]] == '*')
            gen->bloqued += 1;
    }
}

void is_bloqued(structure_t *gen, char **map, int stockpos[(gen->size)][2])
{
    gen->possibilities = 0;
    gen->bloqued = 0;
    is_bloqued_up_down(gen, map);
    is_bloqued_left_right(gen, map);

    if (gen->bloqued == gen->possibilities && gen->bloqued != 0) {
        gen->x = stockpos[gen->count - 1][0];
        gen->y = stockpos[gen->count - 1][1];
        gen->count -= 1;
    }

}
