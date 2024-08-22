/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-wilson.bordichon
** File description:
** solver_struct
*/

#ifndef SOLVER_STRUCT_H_
    #define SOLVER_STRUCT_H_
typedef struct {
    int width;
    int height;
} MapSize;

typedef struct {
    int start;
    int end;
} MapWalk;

typedef struct {
    char *buff;
    int **array;
    int r;
    int s;
    int i;
} ReplaceParams;

typedef struct {
    int x;
    int y;
    int **array;
    int rows;
    int cols;
} DfsParams;

#endif /* !SOLVER_STRUCT_H_ */
