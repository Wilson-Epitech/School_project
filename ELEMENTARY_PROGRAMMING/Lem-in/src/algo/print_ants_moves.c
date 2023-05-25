/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** matrix
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

void print_ant_moves(const stock_pos_t *positions,
structure_t start_end[2], char **room_array)
{
    my_putstr("#moves\n");
    int count[start_end[0].nb_of_ants];
    for (int x = 0; x != start_end[0].nb_of_ants; x++) {
        count[x] = 0;
    }
    char *str = fill_str(positions);

    int check_end = start_end[0].nb_of_ants;
    start_end[0].tour_count = 0;
    while (check_end > 0) {
        check_end = start_end[0].nb_of_ants;
        run_through_to_print(positions, start_end, count, room_array);
    my_putchar('\n');
    start_end[0].tour_count += 1;
    check_end = check_ant_destination_reached
    (count, str, start_end[0].nb_of_ants);
    }
}
