/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** check_generator
*/

#include "../../include/my.h"
#include "../../include/generator.h"

int check_generator_type(int ac, char **av)
{
    char *perfect_map = "perfect";
    if (ac == 4 && strcmp(perfect_map, av[3]) == 0) {
        return 1;
    } else if (ac == 4) {
        exit(84);
    }
    if (ac == 3) {
        return 2;
    }

}
