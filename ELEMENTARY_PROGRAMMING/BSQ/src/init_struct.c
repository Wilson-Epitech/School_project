/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** init_struct
*/

#include "../includes/lib.h"

void init_array_struct(BSQ_T *ALL, int ac, char **av)
{
    struct stat sb;
    stat(av[1], &sb);
    if (sb.st_size == 0)
        exit(84);
    invalid_nb_args(ALL, ac);
    ALL->array.buff = malloc((sizeof(char)) * (sb.st_size + 1));
    ALL->array.map = malloc((sizeof(char)) * (sb.st_size + 1));
    ALL->array.i = 0;
    int fd = open(av[1], O_RDONLY);
    read(fd, ALL->array.buff, sb.st_size);
    error_invalid_char_buffer(ALL);
    empty_file(ALL, ac);
    ALL->array.buff[sb.st_size] = '\0';
    ALL->array.nb_line = my_getnbr(ALL->array.buff);
    ALL->array.min_value = 0;
    ALL->array.nb_max = 0;
    int pos_r_max = 0;
    int pos_s_max = 0;
    ALL->array.map = my_str_to_word_array(ALL->array.buff);
}

void init_array_pos(BSQ_T *ALL)
{
    ALL->array.top_pos = 0;
    ALL->array.top_left_pos = 0;
    ALL->array.left_pos = 0;
}

void init(BSQ_T *ALL, int ac, char **av)
{
    init_array_struct(ALL, ac, av);
    init_array_pos(ALL);
}
