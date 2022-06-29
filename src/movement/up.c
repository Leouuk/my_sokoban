/*
** EPITECH PROJECT, 2022
** sokoban project
** File description:
** move up
*/

#include "sokoban.h"

static void check_wall_case(game_t *game)
{
    if (game->map[game->pos.y - 1][game->pos.x] == '#'
    || game->map[game->pos.y - 1][game->pos.x] == '\0')
        return;
}

static void check_box_case(game_t *game)
{
    if (game->map[game->pos.y - 1][game->pos.x] == 'X') {
        if (game->map[game->pos.y - 2][game->pos.x] == 'X'
        || game->map[game->pos.y - 2][game->pos.x] == '#')
            return;
        if (game->map[game->pos.y - 2][game->pos.x] == ' '
        || game->map[game->pos.y - 2][game->pos.x] == 'O') {
            game->map[game->pos.y - 2][game->pos.x] = 'X';
            game->map[game->pos.y - 1][game->pos.x] = 'P';
            game->map[game->pos.y][game->pos.x] = ' ';
            game->pos.y -= 1;
            return;
        }
    }
}

static void check_player_case(game_t *game)
{
    if (game->map[game->pos.y - 1][game->pos.x] == ' '
    || game->map[game->pos.y - 1][game->pos.x] == 'O') {
        game->map[game->pos.y - 1][game->pos.x] = 'P';
        game->map[game->pos.y][game->pos.x] = ' ';
        game->pos.y -= 1;
        return;
    }
}

void move_up(game_t *game)
{
    check_wall_case(game);
    check_player_case(game);
    check_box_case(game);
}
