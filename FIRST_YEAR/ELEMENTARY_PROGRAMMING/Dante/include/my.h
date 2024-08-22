/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include "struct.h"

int my_strlen(char const *str);
int my_strcmp_custom(char const *str1, char const *str2, int start);


int is_delimiter(char c, char *delim);
int cut_str(char const *str, char *delim);
int check_character(char const *str, char *delim, int cut_here);
char **word_array_delimiter(char const *str, char *delim);

#endif
