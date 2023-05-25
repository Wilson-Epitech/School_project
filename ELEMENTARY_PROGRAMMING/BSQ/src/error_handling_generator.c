/*
** EPITECH PROJECT, 2023
** bsf_modif_sans_casser
** File description:
** error_handling_generator
*/

#include "../includes/lib.h"

void error_handling_error(char *str, char **av, int nb, int i)
{
    if (nb == 1 && i == 0 && str[i] == 'o') {
        exit(84);
    }
    if (str[i] != '.' && str[i] != 'o') {
        exit(84);
    }
}

void error_handling_no_error(char *str, char **av, int nb, int i)
{
    if (nb == 1 && i == 0 && str[i] == '.') {
        my_putchar('x');
        my_putchar('\n');
        exit(0);
    }
    if (i = 1 && nb == 2 && str[0] == '.' && str[1] == 'o') {
        my_putstr("xo");
        my_putchar('\n');
        exit(0);
    }
    if (i = 1 && nb == 2 && str[0] == 'o' && str[1] == '.') {
        my_putstr("ox");
        my_putchar('\n');
        exit(0);
    }
}

int error_handling_generator(BSQ_T *ALL, char *str, char **av)
{
    int nb = my_getnbr(av[1]);
    for (int i = 0; str[i] != '\0'; i++) {
        error_handling_error(av[2], av, nb, i);
        error_handling_no_error(av[2], av, nb, i);
        break;
    }
    return 0;
}
