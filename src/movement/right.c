/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leopold.sallan-gemard
** File description:
** right
*/

#include "sokoban.h"

static void check_wall_case(game_t *game)
{
    if (game->map[game->pos.y][game->pos.x + 1] == '#'
    || game->map[game->pos.y][game->pos.x + 1] == '\0')
        return;
}

static void check_box_case(game_t *game)
{
    if (game->map[game->pos.y][game->pos.x + 1] == 'X') {
        if (game->map[game->pos.y][game->pos.x + 2] == 'X'
        || game->map[game->pos.y][game->pos.x + 2] == '#')
            return;
        if (game->map[game->pos.y][game->pos.x + 2] == ' '
        || game->map[game->pos.y][game->pos.x + 2] == 'O') {
            game->map[game->pos.y][game->pos.x + 2] = 'X';
            game->map[game->pos.y][game->pos.x + 1] = 'P';
            game->map[game->pos.y][game->pos.x] = ' ';
            game->pos.x += 1;
            return;
        }
    }
}

static void check_player_case(game_t *game)
{
    if (game->map[game->pos.y][game->pos.x + 1] == ' '
    || game->map[game->pos.y][game->pos.x + 1] == 'O') {
        game->map[game->pos.y][game->pos.x + 1] = 'P';
        game->map[game->pos.y][game->pos.x] = ' ';
        game->pos.x += 1;
        return;
    }
}

void move_right(game_t *game)
{
    check_wall_case(game);
    check_player_case(game);
    check_box_case(game);
}
