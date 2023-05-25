/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** error_handling
*/

#include "../../include/my.h"
#include "../../include/generator.h"

int check_nbr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
        if (str[0] == '0') {
            return 84;
        }
    }
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 4) {
        exit(84);
    }

    int str_av1 = check_nbr(av[1]);
    int str_av2 = check_nbr(av[2]);

    if (str_av1 == 84 || str_av2 == 84) {
        exit(84);
    }

    return 0;
}
