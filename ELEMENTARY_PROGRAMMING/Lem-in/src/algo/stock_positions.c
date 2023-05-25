/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** matrix
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

void my_add_pos_to_list(int element, stock_pos_t **positions)
{
    stock_pos_t *new_elem = malloc(sizeof(*new_elem));
    stock_pos_t *last = *positions;

    new_elem->data = element;
    new_elem->next = NULL;

    if (*positions == NULL) {
        *positions = new_elem;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_elem;
    }
}

int list_len(const stock_pos_t *positions)
{
    int len = 0;
    positions = positions->next;
    while (positions != NULL) {
        positions = positions->next;
        len++;
    }
    return len;
}

char *fill_str(const stock_pos_t *positions)
{
    int len = list_len(positions);
    char *str = malloc(sizeof(char) * (len + 1));

    str[len] = '\0';
    positions = positions->next;
    for (int i = 0; i != len; i++) {
        str[i] = positions->data + '0';
        positions = positions->next;
    }
    return str;
}

void run_through_to_print(const stock_pos_t *positions,
structure_t start_end[2], int *count, char **room_array)
{
    int check = start_end[0].nb_of_ants;
    char *str = fill_str(positions);
    for (int x = 0; x != start_end[0].nb_of_ants; x++) {
        (str[count[x]] == '\0') ? check -= 1 : 0;
    }
    for (int y = 0; y != start_end[0].nb_of_ants; y++) {
        if (y <= start_end[0].tour_count && str[count[y]] != '\0') {
            my_putstr("P");
            my_put_nbr(y + 1);
            my_putchar('-');
            int nb = str[count[y]] - '0';
            my_putstr(room_array[nb]);
            (y < start_end[0].tour_count && check > 1) ?
            my_putchar(' '), check -= 1 : 0;
            count[y]++;
        }
    }
}

int check_ant_destination_reached(int* count, char* str, int nb_of_ants)
{
    int check_end = nb_of_ants;
    for (int x = 0; x != nb_of_ants; x++) {
        if (str[count[x]] == '\0')
            check_end -= 1;
    }
    return check_end;
}
