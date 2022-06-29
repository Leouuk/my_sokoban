/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** rules
*/

#include "my.h"

int rules(void)
{
    my_putstr("USAGE :\n");
    my_putstr(" ./my_sokoban map.txt\n\n");
    my_putstr("DESCRIPTION :\n");
    my_putstr("	map file representing the warehouse map, containing '#'");
    my_putstr(" for walls, 'P' for the player, 'X' for boxes and 'O'");
    my_putstr(" for storage locations.\n");
    return 0;
}
