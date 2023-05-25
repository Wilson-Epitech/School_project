/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** solver
*/

#include "../../include/my.h"
#include "../../include/solver.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    MapWalk mapwalk;
    MapSize mapsize;
    char *buff = NULL;
    int **array = NULL;
    error_handling(ac, av, buff);
    buff = open_file(ac, av, buff);
    error_invalid_char_buffer(buff);
    set_start_end_maze(buff, &mapwalk);
    map_dimensions(buff, &mapsize);
    array = malloc(sizeof(int*) * mapsize.height);
    array = replace_char(array, buff, &mapsize);
    int check_solve = algo_solv_loop(array, &mapwalk, &mapsize);
    if (check_solve == -1) {
        printf("no solution found");
        return 0;
    }
    print_array_solver(array, &mapsize);
    free(buff);
    free_array_solver(array, &mapsize);
    return 0;
}
