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

linked_list_t *copy_list(linked_list_t *list)
{
    linked_list_t *copy;
    linked_list_t *tmp = NULL;

    while (list) {
        copy = malloc(sizeof(linked_list_t));
        copy->data = my_strdup(list->data);
        copy->next = tmp;
        tmp = copy;
        list = list->next;
    }
    return copy;
}

void my_add_to_list(char *element, linked_list_t **list)
{
    linked_list_t *new_elem = malloc(sizeof(*new_elem));
    linked_list_t *last = *list;

    new_elem->data = element;
    new_elem->next = NULL;

    if (*list == NULL) {
        *list = new_elem;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_elem;
    }
}

void parse_rooms(char *str, count_all_t *count,
linked_list_t **rooms, linked_list_t **rooms_pos)
{
    char **room_line = word_array_delimiter(str, " \n");

    if (is_a_room(str) == 0) {
        my_add_to_list(room_line[0], rooms);
        my_add_to_list(room_line[1], rooms_pos);
        my_add_to_list(room_line[2], rooms_pos);
        count->count_room += 1;
        my_putstr(room_line[0]);
        my_putchar(' ');
        my_putstr(room_line[1]);
        my_putchar(' ');
        my_putstr(room_line[2]);
        my_putchar('\n');
    }
}

int parse_tunnels(char *str, int parsing_state, linked_list_t **tunnels)
{
    char **tunnel_line = word_array_delimiter(str, " -\n");

    if (parsing_state == 0 && is_a_tunnel(str) == 0) {
        parsing_state = 4;
        my_putstr("#tunnels\n");
    }
    if (parsing_state == 4 && is_a_tunnel(str) == 0) {
            my_add_to_list(tunnel_line[0], tunnels);
            my_add_to_list(tunnel_line[1], tunnels);
            my_putstr(tunnel_line[0]);
            my_putchar('-');
            my_putstr(tunnel_line[1]);
            my_putchar('\n');
    }
    if (parsing_state == 4 && is_a_tunnel(str) == 1
    && is_a_com(str) == 1 && is_empty_line(str) == 1) {
        parsing_state = 84;
    }
    return parsing_state;
}
