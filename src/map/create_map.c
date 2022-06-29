/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** ncursesdemo
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "sokoban.h"

int create_2d_map(game_t *game, char *argv[])
{
    char *line = NULL;
    FILE *map = NULL;
    size_t lenght = 0;
    ssize_t nread = 0;
    int index_map = 0;

    if (!game || !argv)
        return 84;
    map = fopen(argv[1], "r");
    game->map = malloc(sizeof(char *) * (game->map_line + 1));
    while ((nread = getline(&line, &lenght, map)) != -1) {
        line[nread] = '\0';
        game->map[index_map] = my_strdup(line);
        ++index_map;
    }
    if (!game->map)
        return 84;
    game->map[index_map] = NULL;
    return 0;
}
