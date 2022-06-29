/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** move_game
*/

#include <curses.h>
#include "sokoban.h"

void move_player(game_t *game, int input, char *argv[])
{
    if (!game || !argv)
        return;
    switch (input) {
        case KEY_UP:
            move_up(game);
            break;
        case KEY_DOWN:
            move_down(game);
            break;
        case KEY_RIGHT:
            move_right(game);
            break;
        case KEY_LEFT:
            move_left(game);
            break;
        case ' ':
            reset_map(game, argv);
            break;
    }
}
