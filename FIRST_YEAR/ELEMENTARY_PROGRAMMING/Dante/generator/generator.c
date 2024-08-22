/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** generator
*/

#include "../include/my.h"
#include "../include/generator.h"

int main(int ac, char **av)
{
    error_handling(ac, av);
    int generator_type = check_generator_type(ac, av);
    int length = atoi(av[1]);
    int width = atoi(av[2]);

    if (generator_type == 1) {
        char *buffer = gen_map_wall(av);
        is_one_line(av, buffer);
        if (length % 2 != 0 && width % 2 != 0)
            generate_perfect_map_impair(av, buffer);
        else
            generate_perfect_map_pair(av, buffer);
    }

    if (generator_type == 2) {
        char *buffer = gen_map_wall(av);
        is_one_line(av, buffer);
        generate_imperfect_map(av, buffer);
    }
    return 0;
}
