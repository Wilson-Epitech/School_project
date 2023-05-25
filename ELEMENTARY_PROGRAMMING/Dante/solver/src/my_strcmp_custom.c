/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** my_strcmp_custom
*/

#include "../../include/my.h"

int my_strcmp_custom(char const *str1, char const *str2, int start)
{
    int y = start;
    int i = 0;
    while (str1[y] != '\0' && str2[i] != '\0') {
        i++;
        y++;
    }
    if (str1[y] == str2[i]) {
        return 0;
    }
    if (str1[y] < str2[i]) {
        return -1;
    } else {
        return 1;
    }

}
