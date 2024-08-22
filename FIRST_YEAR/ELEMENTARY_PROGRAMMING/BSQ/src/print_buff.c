/*
** EPITECH PROJECT, 2023
** print buff
** File description:
** bsq
*/

#include "../includes/lib.h"

void print_buff(BSQ_T *ALL)
{
    for (int i = ALL->array.i; ALL->array.buff[i] != '\0'; i++) {
        my_putchar(ALL->array.buff[i]);
    }
}
