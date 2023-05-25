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

int is_line_valid(char *str, int parsing_state)
{
    if (parsing_state == 0) {
        if (is_a_com(str) == 1 && is_an_instruction(str) == 1
            && is_ant_line(str) == 1 && is_a_room(str) == 1
            && is_a_tunnel(str) == 1 && is_empty_line(str) == 1) {
            return (84);
        }

    }
    return (0);
}

int check_nb_of_commands(count_all_t *count)
{
    if (count->count_startline != 1
    || count->count_endline != 1) {
        return (84);
    }
    return (0);
}
