/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "parsing.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac != 1)
        return (84);

    structure_t start_end[2];
    count_all_t *count = malloc(sizeof(count_all_t));
    linked_list_t *rooms = NULL;
    linked_list_t *tunnels = NULL;
    int_list_t *tunnels2 = NULL;
    if (count == NULL)
        return (84);
    init_count(count);
    if (parsing_input(start_end, &rooms, &tunnels, count) == 84)
        return (84);
    if (error_handling(count, start_end, rooms, tunnels) == 84)
        return (84);
    char **room_array = create_array_name(count, rooms, start_end);
    rename_rooms(tunnels, &tunnels2, room_array);
    int **array = modify_matrix_tunnel(count, tunnels2);
    find_path(array, start_end, count, room_array);
    return (0);
}
