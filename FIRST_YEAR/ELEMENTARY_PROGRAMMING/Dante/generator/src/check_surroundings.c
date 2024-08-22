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

void check_up(structure_t *gen, char **map)
{
    if (gen->case_x >= 0 && gen->case_x <= gen->length_map && gen->case_y >= 0
    && gen->case_y <= gen->width_map && gen->rand_number == 3) {
        if (map[gen->case_x][gen->case_y] == 'X'
        && map[gen->case_x + 1][gen->case_y] == 'X') {
            map[gen->case_x][gen->case_y] = '*';
            map[gen->case_x + 1][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
        if (map[gen->case_x][gen->case_y] == 'X' &&
        gen->case_x == gen->length_map - 1 && gen->length_map % 2 != 0) {
            map[gen->case_x][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
    }
}

void check_down(structure_t *gen, char **map)
{

    if (gen->case_x >= 0 && gen->case_x <= gen->length_map && gen->case_y >= 0
    && gen->case_y <= gen->width_map && gen->rand_number == 0) {
        if (map[gen->case_x][gen->case_y] == 'X' &&
        map[gen->case_x - 1][gen->case_y] == 'X') {
            map[gen->case_x][gen->case_y] = '*';
            map[gen->case_x - 1][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
        if (map[gen->case_x][gen->case_y] == 'X' &&
        gen->case_x == gen->length_map && gen->length_map % 2 != 0) {
            map[gen->case_x][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
    }
}

void check_left(structure_t *gen, char **map)
{
    if (gen->case_x >= 0 && gen->case_x <= gen->length_map && gen->case_y >= 0
    && gen->case_y <= gen->width_map && gen->rand_number == 2) {
            if (map[gen->case_x][gen->case_y] == 'X' &&
            map[gen->case_x][gen->case_y + 1] == 'X') {
                map[gen->case_x][gen->case_y] = '*';
                map[gen->case_x][gen->case_y + 1] = '*';
                gen->x = gen->case_x; gen->y = gen->case_y;
                gen->count += 1;
            }
            if (map[gen->case_x][gen->case_y] == 'X' &&
            gen->case_y == gen->width_map - 1 && gen->width_map % 2 != 0) {
            map[gen->case_x][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
    }
}

void check_right(structure_t *gen, char **map)
{
    if (gen->case_x >= 0 && gen->case_x <= gen->length_map && gen->case_y >= 0
    && gen->case_y <= gen->width_map && gen->rand_number == 1) {
        if (map[gen->case_x][gen->case_y] == 'X' &&
        map[gen->case_x][gen->case_y - 1] == 'X') {
            map[gen->case_x][gen->case_y] = '*';
            map[gen->case_x][gen->case_y - 1] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
        if (map[gen->case_x][gen->case_y] == 'X' &&
        gen->case_y == gen->width_map && gen->width_map % 2 != 0) {
            map[gen->case_x][gen->case_y] = '*';
            gen->x = gen->case_x; gen->y = gen->case_y;
            gen->count += 1;
        }
    }
}

void check_surroundings(structure_t *gen, char **map)
{
    check_up(gen, map);
    check_down(gen, map);
    check_left(gen, map);
    check_right(gen, map);
}
