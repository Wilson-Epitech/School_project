/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** pool
*/

#include "my.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
