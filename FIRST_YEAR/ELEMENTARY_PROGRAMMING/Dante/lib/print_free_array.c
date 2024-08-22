/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "../include/my.h"

void print_array(char **array)
{
    for (int x = 0; array[x] != NULL; x++) {
        if (array[x + 1] != NULL) {
            printf("%s\n", array[x]);
        } else {
            printf("%s", array[x]);
        }
    }
}

void free_array(char **array)
{
    for (int x = 0; array[x] != NULL; x++) {
        free(array[x]);
    }
    free(array);
}
