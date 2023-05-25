/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include "struct.h"
int error_handling(int ac, char **av);
int check_generator_type(int ac, char **av);
int is_one_line(char **av, char *buffer);
char *gen_map_wall(char **av);
void init_all(structure_t *gen, char **map, char **av);
void check_surroundings(structure_t *gen, char **map);
void attribute_new_cases(structure_t *gen);
void is_bloqued(structure_t *gen, char **map, int stockpos[gen->size][2]);
void check_end(structure_t *gen, char **map);
int generate_imperfect_map(char **av, char *buffer);
int generate_perfect_map_pair(char **av, char *buffer);
int generate_perfect_map_impair(char **av, char *buffer);
void print_array(char **array);
void free_array(char **array);
#endif
