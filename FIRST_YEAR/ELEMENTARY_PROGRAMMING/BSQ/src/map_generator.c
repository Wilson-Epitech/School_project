/*
** EPITECH PROJECT, 2023
** map_generator
** File description:
** bsq
*/

#include "../includes/lib.h"

int map_generator_extend(BSQ_T *ALL, char *line)
{
    ALL->array.buff = line;
    ALL->array.map = my_str_to_word_array(ALL->array.buff);
    assign_values_array(ALL);
    replace_char(ALL);
    find_bsq(ALL);
    find_max_nb(ALL);
    find_min_nb(ALL);
    replace_bsq_generator(ALL);
    print_array_generator(ALL);
    return 0;
}

int map_generator(BSQ_T *ALL, char *str, char **av)
{
    int nb_line = my_getnbr(av[1]); int width_line = my_getnbr(av[1]);
    int i = 0; int x = 0; int s = 0;

    char line[width_line * width_line + width_line];
    line[width_line + width_line + width_line] = '\0';
    for (int r = 0; r < nb_line; r++) {
        for (s = 0; s < width_line; s++) {
            if (str[i] == '\0') {
                i = 0;
            }
            line[x] = str[i];
            i ++;
            x ++;
        }
        line[x] = '\n';
        x ++;
        s = 0;
    }
    map_generator_extend(ALL, line);
    return 0;
}
