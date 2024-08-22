/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** pool
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }

    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb <= 9) {
            my_putchar(nb + '0');
    }
}