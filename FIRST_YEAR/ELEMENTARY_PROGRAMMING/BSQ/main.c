/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "includes/lib.h"
#include <string.h>

int assign_values_array(BSQ_T *ALL)
{
    ALL->array.width = width_of_array(ALL);
    ALL->array.width_line = strlen_char_of_line(ALL);
    ALL->array.i = before_first_char(ALL);
    ALL->array.array = malloc(sizeof(int*) * ALL->array.nb_line + 1);
    return 0;
}

void call_func(BSQ_T *ALL)
{
    assign_values_array(ALL);
    replace_char(ALL);
    find_bsq(ALL);
    find_max_nb(ALL);
    find_min_nb(ALL);
    replace_bsq(ALL);
    print_array(ALL);
}

void replace_bsq_one(BSQ_T *ALL)
{
    for (int i = 0; ALL->array.buff[i] != '\0'; i++) {
        if (ALL->array.buff[i] == '.') {
            ALL->array.buff[i] = 'x';
            break;
        }
    }
}

int bsq_option(BSQ_T *ALL, int ac, char **av)
{
    int width_line = strlen_char_of_line(ALL);

    if (ALL->array.nb_line == 1 || width_line == 1) {
        assign_values_array(ALL);
        replace_bsq_one(ALL);
        print_buff(ALL);
    }
    if (ALL->array.nb_line > 1 && width_line > 1) {
        call_func(ALL);
    }
    return 0;
}

int main(int ac, char **av, char *buff)
{
    BSQ_T ALL;
    if (ac == 3) {
        error_handling_generator(&ALL, av[2], av);
        init_generator(&ALL, av);
        map_generator(&ALL, av[2], av);
    }
    if (ac != 3) {
        init(&ALL, ac, av);
        bsq_option(&ALL, ac, av);
    }
    return 0;
}
