/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** free_memory
*/

#include <stdlib.h>
#include "sokoban.h"

void free_elem(game_t *game)
{
    free(game->buffer);
    free(game->map);
    free(game->map_saved);
    free(game);
}
