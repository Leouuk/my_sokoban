/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** print
*/

#include <curses.h>
#include <stddef.h>
#include "sokoban.h"

void print_map(game_t *game)
{
    for (int y = 0; y < game->map_line; ++y) {
        move((LINES / 2 + y - game->map_line / 2),
        (COLS / 2 - game->map_col / 2));
        printw("%s\n", game->map[y]);
    }
}
