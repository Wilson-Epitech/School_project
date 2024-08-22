/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** set_start_end_maze
*/

#include "../../include/solver.h"

int set_start_end_maze(char *buff, MapWalk *mapwalk)
{
    int i = 0;
    mapwalk->start = buff[0];
    while (buff[i] != '\0') {
        i++;
    }
    mapwalk->end = buff[i - 2];
    return 0;
}
