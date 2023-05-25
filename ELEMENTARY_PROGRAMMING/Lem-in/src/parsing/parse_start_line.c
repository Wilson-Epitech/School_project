/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "parsing.h"
#include <stdio.h>

void print_start_room(structure_t start_end[2])
{
    my_putstr("##start\n");
    my_putstr(start_end[0].room_name);
    my_putchar(' ');
    my_put_nbr(start_end[0].pos_x);
    my_putchar(' ');
    my_put_nbr(start_end[0].pos_y);
    my_putchar('\n');
}

int fill_start(char **start_line, structure_t start_end[2])
{
    if (is_alphanum(start_line[0]) == 1 ||
        is_number(start_line[1]) == 1 ||
        is_number(start_line[2]) == 1) {
            return (84);
    }

    if (is_alphanum(start_line[0]) == 0) {
        start_end[0].room_name = start_line[0];
    }

    if (is_number(start_line[1]) == 0) {
        start_end[0].pos_x = my_getnbr(start_line[1]);
    }

    if (is_number(start_line[2]) == 0) {
        start_end[0].pos_y = my_getnbr(start_line[2]);
    }
    return (0);
}

int parse_start(char *str, structure_t start_end[2])
{
    char **start_line = word_array_delimiter(str, " \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; start_line[nb_of_str] != NULL; nb_of_str++) {}
    if (nb_of_str >= 4) {
        if (is_a_com(start_line[3]) == 1)
            return (84);
    }
    if (nb_of_str >= 3 && is_a_com(start_line[0]) == 1) {
        if (fill_start(start_line, start_end) == 84) {
            return (84);
        } else {
            print_start_room(start_end);
            return (0);
        }
    }
    if (is_empty_line(str) == 1 && is_a_com(start_line[0]) == 1
    && nb_of_str <= 2) {
        return (84);
    }
    return (1);
}

int check_start_line(char *str, int parsing_state, structure_t start_end[2],
count_all_t *count)
{
    if (parsing_state == 1) {
        parsing_state = parse_start(str, start_end);
        return parsing_state;
    }
    char **array = word_array_delimiter(str," \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; array[nb_of_str] != NULL; nb_of_str++) {}
    if (my_strcmp("##start", array[0]) == 0
    && parsing_state == 0 && nb_of_str >= 1) {
        count->count_startline++;
        parsing_state = 1;
    }
    if (my_strcmp("##start", array[0]) == 0 && nb_of_str > 1) {
        if (is_a_com(array[1]) == 1) {
            return (84);
        }
    }
    return parsing_state;
}
