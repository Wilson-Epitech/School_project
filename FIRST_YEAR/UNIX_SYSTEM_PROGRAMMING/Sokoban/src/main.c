/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-wilson.bordichon
** File description:
** main
*/

#include "../include/lib.h"

int find_p_position(GAME_T *ALL, int r, int s)
{
    if (ALL->array.array[r][s] == 'P') {
            ALL->player_pos_values.x = r;
            ALL->player_pos_values.y = s;
    }
    return 0;
}

int browse_array(GAME_T *ALL)
{
    for (int r = 0; ALL->array.array[r] != NULL; r++) {
        for (int s = 0; ALL->array.array[r][s] != '\0'; s++) {
            find_p_position(ALL, r, s);
        }
    }
    return 0;
}

int flag_h(int ac, char **av)
{
    const char *flag_h_info = "USAGE\n" "      ./my_sokoban map"
    "\nDESCRIPTION\n"
    "      map file representing the warehouse map, containing ‘#’ for walls,"
    "‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n";

    if (ac == 2 && ( av[1][0] == '-' && av[1][1] == 'h')) {
        my_putstr(flag_h_info);
        exit(0);
    }
    return 0;
}

int main(int ac, char **av)
{
    flag_h(ac, av);
    GAME_T ALL;
    init(&ALL, ac, av);
    char c = 0; int ch;
    error_loop(&ALL);
    initscr();
    noecho();
    browse_array(&ALL);
    while (c != 32) {
        keys(&ALL, ch);
        respawn_o(&ALL);
        for (int x = 0; ALL.array.array[x] != NULL; x++) {
            mvprintw(x, 0, "%s\n", ALL.array.array[x]);
        }
        ch = getch();
        c = ch;
    }
    clear();
    endwin();
    return 0;
}
