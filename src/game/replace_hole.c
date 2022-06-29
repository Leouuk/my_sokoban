/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** replace_holec
*/

#include <stddef.h>
#include "sokoban.h"

static void replace_hole(game_t *game, int y, int x)
{
    if (game->map_saved[y][x] == 'O' && game->map[y][x] == ' ')
        game->map[y][x] = 'O';
}

void check_if_box_on_hole(game_t *game)
{
    for (int y = 0; game->map[y] != NULL; ++y)
        for (int x = 0; game->map[y][x] != '\0'; ++x)
            replace_hole(game, y, x);
}
