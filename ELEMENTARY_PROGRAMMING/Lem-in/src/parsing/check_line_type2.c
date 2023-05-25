/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (1);
        }
    }

    if (my_strlen(str) > 0) {
        return (0);
    }

    return (1);
}

int is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0') || (str[i] > '9' && str[i] < 'A') ||
        (str[i] > 'Z' && str[i] < 'a') || (str[i] > 'z')) {
            return (1);
        }
    }

    if (my_strlen(str) > 0) {
        return (0);
    }

    return (1);
}

int is_empty_line(char *str)
{
    if (my_strlen(str) == 1) {
        if (str[0] == '\n') {
            return (0);
        }
    }

    return (1);
}

int is_a_com(char *str)
{
    if (my_strlen(str) > 1) {
        if (str[0] == '#' && str[1] != '#') {
            return (0);
        }
    }

    return (1);
}

int is_an_instruction(char *str)
{
    if (my_strlen(str) > 2) {
        if (str[0] == '#' && str[1] == '#') {
            return (0);
        }
    }

    return (1);
}
