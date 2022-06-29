/*
** EPITECH PROJECT, 2022check_is_map_valid
** Untitled (Workspace)
** File description:
** set_pos
*/

#include <stdlib.h>
#include <curses.h>
#include "sokoban.h"

static void save_player_position(game_t *game, int y, int x)
{
    if (check_is_map_valid(game, y, x) == 84) {
        free_elem(game);
        endwin();
        exit(84);
    }
    if (game->map[y][x] == 'P') {
        game->pos.y = y;
        game->pos.x = x;
    }
}

void get_player_position(game_t *game)
{
    for (int y = 0; y < game->map_line; ++y) {
        for (int x = 0; x < game->map_col; ++x) {
            save_player_position(game, y, x);
        }
    }
}
