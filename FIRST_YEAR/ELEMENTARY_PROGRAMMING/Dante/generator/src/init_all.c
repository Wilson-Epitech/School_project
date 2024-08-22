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

int init_values(structure_t *gen, char **map, char **av)
{
    gen->x = 0;
    gen->y = 0;
    map[gen->x][gen->y] = '*';
    gen->width_map = atoi(av[1]) - 1;
    gen->length_map = atoi(av[2]) - 1;
    gen->exit_loop = 1;
    gen->count = 0;
    gen->size = gen->length_map * gen->width_map;
}

void init_int_array(structure_t *gen, char **map)
{
    gen->cases = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++)
        gen->cases[i] = malloc(sizeof(int) * 2);
    gen->cases[0][0] = gen->x + 2;
    gen->cases[0][1] = gen->y;
    gen->cases[1][0] = gen->x;
    gen->cases[1][1] = gen->y + 2;
    gen->cases[2][0] = gen->x;
    gen->cases[2][1] = gen->y - 2;
    gen->cases[3][0] = gen->x - 2;
    gen->cases[3][1] = gen->y;
    gen->rand_number = rand () % 4;
    gen->case_x = gen->cases[gen->rand_number][0];
    gen->case_y = gen->cases[gen->rand_number][1];
}

void init_all(structure_t *gen, char **map, char **av)
{
    init_values(gen, map, av);
    init_int_array(gen, map);
}
