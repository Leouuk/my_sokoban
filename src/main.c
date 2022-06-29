/*
** EPITECH PROJECT, 2022
** sokoban project
** File description:
** main function that call
*/

#include <stddef.h>
#include "sokoban.h"

int main(int const argc, char *argv[], char *env[])
{
    if (check_arg(argc, argv) == 84 || check_env(env) == 84)
        return 84;
    return sokoban(argv);
}
