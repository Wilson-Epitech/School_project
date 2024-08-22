/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-lemin-eva.legrand
** File description:
** stock_room_name
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

char **create_array_name(count_all_t *count,
linked_list_t *rooms, structure_t start_end[2])
{
    char **array_room = malloc(sizeof(char *) * count->count_room + 1);
    int i = 0;
    int len = my_strlen(start_end[0].room_name);
    array_room[i] = malloc(sizeof(char) * len + 1);
    array_room[i] = start_end[0].room_name;
    i += 1;
    while (i != (count->count_room - 1)) {
        len = my_strlen(rooms->data);
        array_room[i] = malloc(sizeof(char) * len + 1);
        array_room[i] = rooms->data;
        rooms = rooms->next;
        i += 1;
    }
    len = my_strlen(start_end[1].room_name);
    array_room[i] = malloc(sizeof(char) * len + 1);
    array_room[i] = start_end[1].room_name;
    return array_room;
}

void my_add_room_to_tunnel_list(int element, int_list_t **tunnels2)
{
    int_list_t *new_elem = malloc(sizeof(*new_elem));
    int_list_t *last = *tunnels2;

    new_elem->data = element;
    new_elem->next = NULL;

    if (*tunnels2 == NULL) {
        *tunnels2 = new_elem;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_elem;
    }
}

void rename_rooms2(const linked_list_t *tunnels,
int_list_t **tunnels2, char **rooms_array)
{
    for (int x = 0; rooms_array[x] != NULL; x++) {
        if (my_strcmp(tunnels->data, rooms_array[x]) == 0) {
            my_add_room_to_tunnel_list(x, tunnels2);
            break;
        }
    }
}

void rename_rooms(const linked_list_t *tunnels,
int_list_t **tunnels2, char **rooms_array)
{
    while (tunnels != NULL) {
        rename_rooms2(tunnels, tunnels2, rooms_array);
        tunnels = tunnels->next;
    }
}
