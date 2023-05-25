/*
** EPITECH PROJECT, 2023
** bsq
** File description:
** count
*/

#include "../includes/lib.h"

int strlen_char_of_line(BSQ_T *ALL)
{
    int i = 0;
    int x = 0;
    int j = 0;

    while (ALL->array.buff[x] != '.' && ALL->array.buff[x] != 'o') {
        x++;
    }
    while (ALL->array.buff[j] != '\0') {
        while (ALL->array.buff[x] != '\n') {
            x++;
            i++;
        }
        j++;
    }
    return i;
}

int width_of_array(BSQ_T *ALL)
{
    int z = 0;
    int y = 0;
    int x = 0;

    while (ALL->array.buff[y] != '\0') {
        while (ALL->array.buff[x] != '.' && ALL->array.buff[x] != 'o') {
                x++;
        }
        y++;
    }
    y = y - x - ALL->array.nb_line;
    return y;
}

int before_first_char(BSQ_T *ALL)
{
    int x = 0;

    while (ALL->array.buff[x] != '.' && ALL->array.buff[x] != 'o') {
        x++;
    }
    return x;
}
