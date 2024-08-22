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

char *gen_map_wall(char **av)
{
    int length_map = atoi(av[1]);
    int width_map = atoi(av[2]);
    int size_map = (length_map * width_map) + width_map;
    char *buffer = malloc(sizeof(char) * (size_map + 1));
    int i = 0;
    for (int x = 0; x != width_map; x++) {
        for (int y = 0; y != length_map; y++) {
            buffer[i] = 'X';
            i += 1;
        }
        buffer[i] = '\n';
        i += 1;
    }
    buffer[i] = '\0';
    return buffer;
}

int generate_imperfect_map(char **av, char *buffer)
{
    structure_t *gen = malloc(sizeof(structure_t));
    char **map = word_array_delimiter(buffer, "\n");
    srand(time(NULL));
    init_all(gen, map, av);
    int stockpos[gen->size][2];
    gen->rand_stars = 0;
    while (gen->exit_loop != 0) {
        check_surroundings(gen, map);
        stockpos[gen->count][0] = gen->x;
        stockpos[gen->count][1] = gen->y;
        attribute_new_cases(gen);
        is_bloqued(gen, map, stockpos);
        gen->rand_number = rand () % 4;
        gen->case_x = gen->cases[gen->rand_number][0];
        gen->case_y = gen->cases[gen->rand_number][1];
        check_end(gen, map);
    }
    print_array(map);
    free_array(map);
}

int generate_perfect_map_impair(char **av, char *buffer)
{
    structure_t *gen = malloc(sizeof(structure_t));
    char **map = word_array_delimiter(buffer, "\n");
    srand(time(NULL));
    init_all(gen, map, av);
    int stockpos[gen->size][2];
    gen->rand_stars = 1;
    while (gen->exit_loop != 0) {
        check_surroundings(gen, map);
        stockpos[gen->count][0] = gen->x;
        stockpos[gen->count][1] = gen->y;
        attribute_new_cases(gen);
        is_bloqued(gen, map, stockpos);
        gen->rand_number = rand () % 4;
        gen->case_x = gen->cases[gen->rand_number][0];
        gen->case_y = gen->cases[gen->rand_number][1];
        check_end(gen, map);
    }
    print_array(map);
    free_array(map);
}

void lines_of_stars(char **map, int x, int rand_order)
{
    for (int y = 0; map[x][y] != '\0'; y++) {
        if (rand_order == 0 && x % 2 != 0) {
            map[x][y] = '*';
        }
        if (rand_order == 1 && x % 2 == 0) {
            map[x][y] = '*';
        }
    }

}

int generate_perfect_map_pair(char **av, char *buffer)
{
    char **map = word_array_delimiter(buffer, "\n");
    int length = atoi(av[1]);
    int width = atoi(av[2]);
    srand(time(NULL));
    int rand_order = rand () % 2;
    map[0][0] = '*';
    map[width - 1][length - 1] = '*';

    for (int x = 0; map[x] != NULL; x++) {
        lines_of_stars(map, x, rand_order);
        if (rand_order == 1 && x % 2 != 0) {
            int rand_star = rand () % length;
            map[x][rand_star] = '*';
        }
        if (rand_order == 0 && x % 2 == 0) {
            int rand_star = rand () % length;
            map[x][rand_star] = '*';
        }
    }
    print_array(map);
}
