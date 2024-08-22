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

int is_ant_line(char *str)
{
    char **ants_line = word_array_delimiter(str, " \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; ants_line[nb_of_str] != NULL; nb_of_str++) {}

    if (nb_of_str == 1 && is_number(ants_line[0]) == 0) {
        return (0);
    }
    if (nb_of_str > 1 && is_number(ants_line[0]) == 0) {
        if (is_a_com(ants_line[1]) == 0) {
            return (0);
        }
    }

    return (1);

}

int is_a_room(char *str)
{
    char **room_line = word_array_delimiter(str, " \n");
    int nb_of_str = 0;
    for (nb_of_str = 0; room_line[nb_of_str] != NULL; nb_of_str++) {}

    if (nb_of_str >= 4) {
        if (is_alphanum(room_line[0]) == 0 && is_number(room_line[1]) == 0
        && is_number(room_line[2]) == 0 && is_a_com(room_line[3]) == 0) {
            return (0);
        }
    }

    if (nb_of_str >= 3) {
        if (is_alphanum(room_line[0]) == 0 && is_number(room_line[1]) == 0
        && is_number(room_line[2]) == 0) {
            return (0);
        }
    }

    return (1);
}

int is_a_tunnel(char *str)
{
    char **tunnel_line = word_array_delimiter(str, " -\n");
    int nb_of_str = 0;
    for (nb_of_str = 0; tunnel_line[nb_of_str] != NULL; nb_of_str++) {}

    if (nb_of_str >= 3) {
        if (is_alphanum(tunnel_line[0]) == 0 &&
            is_alphanum(tunnel_line[1]) == 0
            && is_a_com(tunnel_line[2]) == 0) {
            return (0);
        }
    }

    if (nb_of_str == 2) {
        if (is_alphanum(tunnel_line[0]) == 0 &&
            is_alphanum(tunnel_line[1]) == 0) {
                return (0);
        }
    }

    return (1);
}
