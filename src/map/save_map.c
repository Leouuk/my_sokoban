/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** save
*/

#include <curses.h>
#include <stdlib.h>
#include <stddef.h>
#include "sokoban.h"

int save_2d_map(game_t *game)
{
    game->map_saved = malloc(sizeof(char *) * (game->map_line + 1));

    if (!game || !game->map_saved)
        return 84;
    for (int y = 0; y < game->map_line; ++y)
        game->map_saved[y] = my_strdup(game->map[y]);
    game->map_saved[game->map_line] = NULL;
    return 0;
}
