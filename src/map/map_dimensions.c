/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** map_dimensions
*/

#include <stddef.h>
#include "sokoban.h"

void get_map_line(game_t *game)
{
    int index = 0;

    if (!game)
        return;
    for (; game->buffer[index] != '\0'; ++index) {
        if (game->buffer[index] == '\n'
        || (game->buffer[index + 1] == '\0' && game->buffer[index] != '\n'))
            ++game->map_line;
    }
}

void get_map_col(game_t *game)
{
    if (!game)
        return;
    for (; game->buffer[game->map_col] != '\n'; ++game->map_col);
}
