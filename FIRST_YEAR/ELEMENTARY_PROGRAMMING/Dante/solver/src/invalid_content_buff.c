/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** invalid_content_buff
*/

#include "../../include/my.h"
#include "../../include/solver.h"

int error_invalid_char_buffer(char *buff)
{
    for (int y = 0; buff[y] != '\0'; y++) {
        if (buff[y] != 'X' && buff[y] != '*'
            && buff[y] != '\n' && (buff[y] > '9' || buff[y] < '0')) {
                printf("error : Invalid content\n");
                exit(84);
            }
    }
    return 0;
}
