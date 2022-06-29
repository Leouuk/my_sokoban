
/*
** EPITECH PROJECT, 2022
** sokoban project
** File description:
** init game
*/

#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"

static int init_struct_value(game_t *game)
{
    if (!game)
        return 84;
    game->map_line = 0;
    game->map_col = 0;
    game->win = true;
    game->buffer = NULL;
    game->map = NULL;
    game->map_saved = NULL;
    game->final_hole = 0;
    return 0;
}

static int init_buffer(game_t *game, char *argv[])
{
    game->buffer = open_read_file(argv[1]);

    if (!game || !game->buffer)
        return 84;
    if (check_number_elem(game) == 84)
        return 84;
    return 0;
}

int init_game(game_t *game, char *argv[])
{
    if (!game || !argv || init_struct_value(game) == 84
    || init_buffer(game, argv) == 84)
        return 84;
    get_map_line(game);
    get_map_col(game);
    if (create_2d_map(game, argv) == 84 || save_2d_map(game) == 84)
        return 84;
    get_player_position(game);
    return 0;
}
