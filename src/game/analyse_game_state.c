/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check_game_state
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>
#include "sokoban.h"

static void check_map(game_t *game, int y, int x)
{
    if (game->map[y][x] == 'X' && game->map_saved[y][x] == 'O')
        ++game->final_hole;
}

bool check_victory(game_t *game)
{
    for (int y = 0; y < game->map_line; ++y) {
        for (int x = 0; game->map[y][x] != '\0'; ++x) {
            check_map(game, y, x);
        }
    }
    if (game->nb_hole == game->final_hole)
        return true;
    game->final_hole = 0;
    return false;
}
