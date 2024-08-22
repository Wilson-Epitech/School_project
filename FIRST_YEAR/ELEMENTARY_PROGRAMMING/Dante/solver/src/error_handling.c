/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** error_handling
*/

#include "../../include/my.h"
#include "../../include/solver.h"

void error_handling(int ac, char **av, char *buff)
{
    struct stat sb;
    if (ac != 2) {
        printf("error : Invalid nb args\n");
        exit(84);
    }
    if (stat(av[1], &sb) != 0 || !S_ISREG(sb.st_mode)) {
        printf("Error: %s is not a valid file\n", av[1]);
        exit(84);
    }
}
