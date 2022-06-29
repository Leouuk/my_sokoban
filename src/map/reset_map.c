/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** reset_map
*/

#include <stdlib.h>
#include <ncurses.h>
#include "sokoban.h"

void reset_map(game_t *game, char *argv[])
{
    if (create_2d_map(game, argv) == 84 || !game || !argv) {
        free_elem(game);
        endwin();
        exit(1);
    }
    get_player_position(game);
    clear();
    refresh();
}
