/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** file
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static char open_file(const char *filepath)
{
    int fd = open(filepath , O_RDONLY);

    if (fd == -1)
        return 84;
    return fd;
}

static char *read_file(const char *filepath, int fd)
{
    int size = 0;
    char *array = NULL;
    struct stat st;

    if (fd == -1)
        return NULL;
    stat(filepath, &st);
    size = st.st_size + 1;
    array = malloc(sizeof(char) * size);
    if (read(fd, array, size) < 1 || array == NULL)
        return NULL;
    array[size -1] = '\0';
    close (fd);
    return (array);
}

char *open_read_file(const char *filepath)
{
    int fd = open_file(filepath);

    if (open_file(filepath) == 84)
        return NULL;
    char *buffer = read_file(filepath, fd);
    if (!buffer || !filepath)
        return NULL;
    return buffer;
}
