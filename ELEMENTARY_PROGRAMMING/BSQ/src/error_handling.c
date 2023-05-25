/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-wilson.bordichon
** File description:
** error_handling
*/

#include "../includes/lib.h"

int invalid_nb_args(BSQ_T *ALL, int ac)
{
    if (ac != 2 && ac != 3) {
        my_putstr("invalid nb args\n");
        exit(84);
    }
    return 0;
}

int empty_file(BSQ_T *ALL, int ac)
{
    if (my_strlen(ALL->array.buff) <= 3 && ac != 3) {
        my_putstr("error : empty file \n");
        exit(84);
    }
    return 0;
}

int error_invalid_char_buffer(BSQ_T *ALL)
{
    for (int y = 0; ALL->array.buff[y] != '\0'; y++) {
        if (ALL->array.buff[y] != '.' && ALL->array.buff[y] != 'o'
            && ALL->array.buff[y] != '\n' && ALL->array.buff[y]
            && (ALL->array.buff[y] > '9' || ALL->array.buff[y] < '0')) {
                my_putstr("error : invalid content\n");
                exit(84);
        }
    }
    return 0;
}
