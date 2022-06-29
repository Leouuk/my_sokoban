/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** calling function
*/

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "sokoban.h"

int loop(game_t *game, char *argv[])
{
    int input = 0;

    if (!game || !argv)
        return 84;
    while (input != 'A' && input != 'a') {
        usleep(2000);
        resize_terminal(game);
        input = getch();
        move_player(game, input, argv);
        check_if_box_on_hole(game);
        if (check_victory(game) == true) {
            usleep(1000000);
            break;
        }
    }
    endwin();
    return 0;
}
