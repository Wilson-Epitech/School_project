/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-lemin-eva.legrand
** File description:
** error_handling
*/

#include "my.h"
#include "parsing.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int compare_elements_array(char *element, char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        if (my_strcmp(element, array[i]) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int error_handling(count_all_t *count, structure_t *start_end,
    linked_list_t *rooms, linked_list_t *tunnels)
{
    char **array_rooms = NULL;

    if (start_end[0].nb_of_ants == 0) {
        return 84;
    }
    array_rooms = create_array_name(count, rooms, start_end);
    while (tunnels != NULL) {
        if (compare_elements_array(tunnels->data, array_rooms) == 1) {
            return 84;
        }
        tunnels = tunnels->next;
    }
    return 0;
}
