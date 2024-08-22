/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** error_handling
*/

#include "../../include/my.h"
#include "../../include/generator.h"

char *single_line(char *buffer, int width_map, int length_map)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X')
            buffer[i] = '*';
    }
    return buffer;
}

int is_one_line(char **av, char *buffer)
{
    int width_map = atoi(av[1]);
    int length_map = atoi(av[2]);

    if (width_map == 1 || length_map == 1) {
        buffer = single_line(buffer, width_map, length_map);
        char **map = word_array_delimiter(buffer, "\n");
        print_array(map);
        exit(0);
    }
}
