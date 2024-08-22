/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>

void init_count(count_all_t *count)
{
    count->count_startline = 0;
    count->count_endline = 0;
    count->count_room = 2;
    count->x = 0;
    count->y = 0;
}

int fill_ants_line(char *str,  structure_t start_end[2], int parsing_state)
{
    if (parsing_state == 3) {
        if (is_ant_line(str) == 0) {
            char **ants_line = word_array_delimiter(str, " \n");
            start_end[0].nb_of_ants = my_getnbr(ants_line[0]);
            my_putstr("#number_of_ants\n");
            my_put_nbr(start_end[0].nb_of_ants);
            my_putchar('\n');
            parsing_state = 0;
            my_putstr("#rooms\n");
        }
        if (is_ant_line(str) == 1 && is_a_com(str) == 1) {
            return (84);
        }
    }
    return parsing_state;
}

int parsing_input(structure_t *start_end,
linked_list_t **rooms, linked_list_t **tunnels, count_all_t *count)
{
    char *str = NULL;
    size_t length = 0;
    ssize_t nread = 0;
    linked_list_t *rooms_pos = NULL;
    int parsing_state = 3;

    while ((nread = getline(&str, &length, stdin)) != -1) {
        parsing_state = fill_ants_line(str, start_end, parsing_state);
        if (parsing_state == 0)
            parse_rooms(str, count, rooms, &rooms_pos);
        parsing_state = check_start_line(str, parsing_state, start_end, count);
        parsing_state = check_end_line(str, parsing_state, start_end, count);
        parsing_state = parse_tunnels(str, parsing_state,  tunnels);
        if (parsing_state == 84 || (is_line_valid(str, parsing_state)) == 84)
            return (84);
    }
    if (check_nb_of_commands(count) == 84)
        return (84);

    return (0);
}
