/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "parsing.h"
#include <stdio.h>

void print_end_room(structure_t start_end[2])
{
    my_putstr("##end\n");
    my_putstr(start_end[1].room_name);
    my_putchar(' ');
    my_put_nbr(start_end[1].pos_x);
    my_putchar(' ');
    my_put_nbr(start_end[1].pos_y);
    my_putchar('\n');
}

int fill_end(char **end_line, structure_t start_end[2])
{
    if (is_alphanum(end_line[0]) == 1 ||
        is_number(end_line[1]) == 1 ||
        is_number(end_line[2]) == 1) {
            return (84);
    }

    if (is_alphanum(end_line[0]) == 0) {
        start_end[1].room_name = end_line[0];
    }

    if (is_number(end_line[1]) == 0) {
        start_end[1].pos_x = my_getnbr(end_line[1]);
    }

    if (is_number(end_line[2]) == 0) {
        start_end[1].pos_y = my_getnbr(end_line[2]);
    }

    return (0);
}

int parse_end(char *str, structure_t start_end[2])
{
    char **end_line = word_array_delimiter(str, " \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; end_line[nb_of_str] != NULL; nb_of_str++) {}
    if (nb_of_str >= 4) {
        if (is_a_com(end_line[3]) == 1)
            return (84);
    }
    if (nb_of_str >= 3 && is_a_com(end_line[0]) == 1) {
        if (fill_end(end_line, start_end) == 84) {
            return (84);
        } else {
            print_end_room(start_end);
            return (0);
        }
    }
    if (is_empty_line(str) == 1 && is_a_com(end_line[0]) == 1
        && nb_of_str <= 2)
        return (84);
    return (2);
}

int check_end_line(char *str, int parsing_state, structure_t start_end[2],
count_all_t *count)
{
    if (parsing_state == 2) {
        parsing_state = parse_end(str, start_end);
        return parsing_state;
    }
    char **array = word_array_delimiter(str," \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; array[nb_of_str] != NULL; nb_of_str++) {}
    if (my_strcmp("##end", array[0]) == 0
    && parsing_state == 0 && nb_of_str >= 1) {
        count->count_endline++;
        parsing_state = 2;
    }
    if (my_strcmp("##end", array[0]) == 0 && nb_of_str > 1) {
        if (is_a_com(array[1]) == 1) {
            return (84);
        }
    }
    return parsing_state;
}
