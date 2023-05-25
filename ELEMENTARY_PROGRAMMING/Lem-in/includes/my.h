/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include "parsing.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
void my_put_nbr(int nb);
char *my_strdup(char const *src);
int my_getnbr(char const *str);
int my_strncmp(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
void print_array(char **array);
void free_array(char **array);

int is_delimiter(char c, char *delim);
int cut_str(char const *str, char *delim);
int check_character(char const *str, char *delim, int cut_here);
char **word_array_delimiter(char const *str, char *delim);

int find_path(int **array, structure_t *start_end,
count_all_t *count, char **room_array);
int** modify_matrix_tunnel(count_all_t *count, int_list_t *tunnels2);
void my_add_pos_to_list(int element, stock_pos_t **positions);
void run_through_to_print(const stock_pos_t *positions,
structure_t start_end[2], int *count, char **room_array);
void print_ant_moves(const stock_pos_t *positions,
structure_t start_end[2], char **room_array);
int check_ant_destination_reached(int* count, char* str, int nb_of_ants);
char * fill_str(const stock_pos_t *positions);
char **create_array_name(count_all_t *count,
linked_list_t *rooms, structure_t start_end[2]);
void rename_rooms(const linked_list_t *tunnels,
int_list_t **tunnels2, char **rooms_array);
int error_handling(count_all_t *count, structure_t *start_end,
linked_list_t *rooms, linked_list_t *tunnels);

#endif
