/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** check_map
*/

#include "sokoban.h"

int check_number_elem(game_t *game)
{
    game->nb_player = 0;
    game->nb_hole = 0;
    game->nb_box = 0;

    if (!game)
        return 84;
    for (int i = 0; game->buffer[i] != '\0'; i += 1) {
        if (game->buffer[i] == 'P')
            game->nb_player += 1;
        if (game->buffer[i] == 'O')
            game->nb_hole += 1;
        if (game->buffer[i] == 'X')
            game->nb_box += 1;
    }
    if (game->nb_player != 1 || game->nb_hole != game->nb_box)
        return 84;
    return 0;
}

int check_is_map_valid(game_t *game, int y, int x)
{
    if (!game || (game->map[y][x] != '\0' && game->map[y][x] != ' '
    && game->map[y][x] != '#'
    && game->map[y][x] != '\n' && game->map[y][x] != 'X'
    && game->map[y][x] != 'O' && game->map[y][x] != 'P'))
        return 84;
    return 0;
}
