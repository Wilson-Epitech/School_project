/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "solver_struct.h"

int my_strcmp_custom(char const *str1, char const *str2, int start);

char *open_file(int ac, char **av, char *buff);
void map_dimensions(char *buff, MapSize *mapsize);
void error_handling(int ac, char **av, char *buff);
int error_invalid_char_buffer(char *buff);
int set_start_end_maze(char *buff, MapWalk *mapwalk);
int print_array(int **array, MapSize *mapsize);
int **replace_char(int **array, char *buff, MapSize *mapsize);
int print_array_solver(int **array, MapSize *mapsize);
bool dfs(DfsParams params);
int algo_solv_loop(int **array, MapWalk *mapwalk, MapSize *mapsize);
int free_array_solver(int **array, MapSize *mapsize);
#endif
