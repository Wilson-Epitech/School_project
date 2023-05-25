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

void gen_stars(structure_t *gen, char **map)
{

    if (gen->rand_stars == 0) {
        int nb_stars = gen->length_map * gen->width_map / 4;
        for (int i = 0; i != nb_stars; i++) {
        int rand_nb1 = rand () % gen->length_map;
        int rand_nb2 = rand () % gen->width_map;
            map[rand_nb1][rand_nb2] = '*';
        }
        gen->exit_loop = 0;
    }

    if (gen->rand_stars == 1) {
        gen->exit_loop = 0;
    }

}

void check_end(structure_t *gen, char **map)
{
    if (map[gen->length_map][gen->width_map] == '*' )
        gen_stars(gen, map);
}
