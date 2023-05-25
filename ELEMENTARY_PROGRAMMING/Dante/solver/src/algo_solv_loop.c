/*
** EPITECH PROJECT, 2023
** test_bfs
** File description:
** algo_solv_loop
*/

#include "../../include/my.h"
#include "../../include/solver.h"

bool check_valid_case(DfsParams params)
{
    int x = params.x;
    int y = params.y;
    int **array = params.array;
    int rows = params.rows;
    int cols = params.cols;

    return (x >= 0 && x < rows && y >= 0 && y < cols && array[x][y] == 0);
}

bool check_case_recursive(DfsParams params)
{
    DfsParams params_next[4] =
        {{params.x + 1, params.y, params.array, params.rows, params.cols},
        {params.x, params.y + 1, params.array, params.rows, params.cols},
        {params.x - 1, params.y, params.array, params.rows, params.cols},
        {params.x, params.y - 1, params.array, params.rows, params.cols}};

    for (int i = 0; i < 4; i++) {
        if (dfs(params_next[i])) {
            return true;
        }
    }
    if (params.array[params.x][params.y] == 2) {
        params.array[params.x][params.y] = 5;
    }
    return false;
}

bool dfs(DfsParams params)
{
    int x = params.x;
    int y = params.y;
    int **array = params.array;
    int rows = params.rows;
    int cols = params.cols;

    if (x == rows - 1 && y == cols - 1) {
        return true;
    }
    if (!check_valid_case(params)) {
        return false;
    }
    array[x][y] = 2;
    if (check_case_recursive(params)) {
        return true;
    }
    return false;
}

int algo_solv_loop(int **array, MapWalk *mapwalk, MapSize *mapsize)
{
    DfsParams params = {0, 0, array, mapsize->height, mapsize->width};
    if (dfs(params) && array[mapsize->height - 1][mapsize->width - 1] != 9) {
        return 1;
    } else {
        return -1;
    }
}
