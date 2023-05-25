/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** matrix
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

static int** create_matrix(count_all_t *count)
{
    int **array = malloc(sizeof(int *) * (count->count_room + 1));

    for (int y = 0; y != count->count_room; y += 1) {
        array[y] = malloc(sizeof(int) * (count->count_room + 1));
        for (int x = 0; x != count->count_room; x += 1) {
            array[y][x] = 0;
        }
    }
    return array;
}

int** modify_matrix_tunnel(count_all_t *count, int_list_t *tunnels2)
{
    int **array = create_matrix(count);
    int first_room = 0;
    int last_room = 0;
    int_list_t *tunnel2 = tunnels2;

    while (tunnel2 != NULL) {
        first_room = tunnel2->data;
        tunnel2 = tunnel2->next;
        if (tunnel2 == NULL)
            break;
        last_room = tunnel2->data;
        tunnel2 = tunnel2->next;
        array[first_room][last_room] = 1;
        array[last_room][first_room] = 1;
    }
    return array;
}

int algo_ants(int **array, count_all_t *count, int save_y)
{
    if (array[count->y][count->x] == 0) {
        count->x += 1;
    }
    if (count->x == count->count_room + 1) {
        count->y = save_y;
        count->x = 0;
    }
    if (array[count->y][count->x] == 1) {
        array[count->y][count->x] = 0;
        if (count->x == save_y) {
            count->x += 1;
        } else {
            save_y = count->y;
            count->y = count->x;
            count->x = 0;
        }
    }
    return save_y;
}

int find_path(int **array, structure_t *start_end,
count_all_t *count, char **room_array)
{
    int room_start = 0;
    int room_end = count->count_room - 1;
    int save_y = 0;
    int count_loop = 0;

    stock_pos_t *positions = NULL;
    count->y = room_start;
    while (count->y != room_end) {
        count_loop += 1;
        save_y = algo_ants(array, count, save_y);
        if (save_y != count->save_prec && count_loop > 2)
            my_add_pos_to_list(count->save_prec, &positions);
        if (count_loop > 400000)
            return 84;
        count->save_prec = save_y;
    }
    my_add_pos_to_list(count->save_prec, &positions);
    my_add_pos_to_list(room_end, &positions);
    print_ant_moves(positions, start_end, room_array);
    return (0);
}
