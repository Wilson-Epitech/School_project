/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** init_generator
*/

#include "../includes/lib.h"

void init_generator(BSQ_T *ALL, char **av)
{
    ALL->array.buff = malloc((sizeof(char)) * (my_strlen(av[2])));
    ALL->array.map = malloc((sizeof(char)) * (200));
    ALL->array.i = 0;
    ALL->array.buff[my_strlen(av[2])] = '\0';
    ALL->array.nb_line = my_getnbr(av[1]);
    ALL->array.min_value = 0;
    ALL->array.nb_max = 0;
    int pos_r_max = 0;
    int pos_s_max = 0;
}
