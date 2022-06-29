/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sokoban
*/

#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "sokoban.h"

int sokoban(char *argv[])
{
    game_t *game = malloc(sizeof(game_t));

    init_ncurses();
    if (!game || init_game(game, argv) == 84) {
        endwin();
        return 84;
    }
    if (loop(game, argv) == 84) {
        endwin();
        return 84;
    }
    print_map(game);
    usleep(1000000);
    endwin();
    free_elem(game);
    return 0;
}
