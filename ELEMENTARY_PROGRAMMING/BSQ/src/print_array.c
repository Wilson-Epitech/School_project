/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** print_array
*/

#include "../includes/lib.h"

int print_array(BSQ_T *ALL)
{
    for (int x = 1; ALL->array.map[x + 1] != NULL; x++) {
            my_putstr(ALL->array.map[x]);
            my_putchar('\n');
    }
    return 0;
}

int print_array_generator(BSQ_T *ALL)
{
    for (int x = 0; ALL->array.map[x + 1] != NULL; x++) {
            my_putstr(ALL->array.map[x]);
            my_putchar('\n');
    }
    return 0;
}
