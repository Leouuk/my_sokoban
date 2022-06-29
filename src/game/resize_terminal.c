/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** resize_map
*/

#include <ncurses.h>
#include "sokoban.h"

void resize_terminal(game_t *game)
{
    int window_width = 0;
    int window_height = 0;

    getmaxyx(stdscr, window_height, window_width);
    if ((game->map_col > window_width) || (game->map_line > window_height)) {
        move(LINES / 2, COLS / 2 - 16);
        printw("Please resize the terminal window");
    } else
        print_map(game);
}
