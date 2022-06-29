/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-leopold.sallan-gemard
** File description:
** error_handling
*/

#include <stddef.h>
#include "sokoban.h"

int check_arg(int const argc, char *argv[])
{
    if ((argc != 2) || (argv == NULL))
        return 84;
    if ((argv[1][0] == '-') && (argv[1][1] == 'h'))
        return (rules());
    return 0;
}

int check_env(char *env[])
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "TERM", 4) == 0)
            return 0;
    }
    return 84;
}
