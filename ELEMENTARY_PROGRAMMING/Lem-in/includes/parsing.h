/*
** EPITECH PROJECT, 2022
** parsing.h
** File description:
** parsing.h
*/

#ifndef PARSING_H_
    #define PARSING_H_
typedef struct {
    char *room_name;
    int pos_x;
    int pos_y;
    int nb_of_ants;
    int tour_count;
} structure_t;

typedef struct {
    int count_antline;
    int count_startline;
    int count_endline;
    int count_room;
    int x;
    int y;
    int save_prec;
} count_all_t;

typedef struct linked_list {
    char *data;
    struct linked_list *next;
} linked_list_t;

typedef struct int_list {
    int data;
    struct int_list *next;
} int_list_t;

typedef struct stock_pos {
    int data;
    struct stock_pos *next;
} stock_pos_t;

int is_number(char *str);
int is_alphanum(char *str);
int is_empty_line(char *str);
int is_a_com(char *str);
int is_an_instruction(char *str);
int is_ant_line(char *str);
int is_a_room(char *str);
int is_a_tunnel(char *str);
int is_line_valid(char *str, int parsing_state);

int check_nb_of_commands(count_all_t *count);
int check_start_line(char *str, int parsing_state, structure_t start_end[2],
count_all_t *count);
int check_end_line(char *str, int parsing_state, structure_t start_end[2],
count_all_t *count);
void parse_rooms(char *str, count_all_t *count,
linked_list_t **rooms, linked_list_t **rooms_pos);
int parse_tunnels(char *str, int parsing_state, linked_list_t **tunnels);
int parsing_input(structure_t *start_end,
linked_list_t **rooms, linked_list_t **tunnels, count_all_t *count);
void init_count(count_all_t *count);
linked_list_t *copy_list(linked_list_t *list);
#endif
