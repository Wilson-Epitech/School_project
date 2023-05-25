/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2)
{
    int i = 0;
    int y = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[y]) {
            y++;
        } else {
            return (1);
        }
        i++;
    }
    return (0);
}
