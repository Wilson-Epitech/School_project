/*
** EPITECH PROJECT, 2022
** day04
** File description:
** task02
*/
#include "../../include/lib.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
