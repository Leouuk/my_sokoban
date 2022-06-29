/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char my_open_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || !filepath)
        return 84;
    return fd;
}
