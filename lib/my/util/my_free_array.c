/*
** EPITECH PROJECT, 2022
** lib
** File description:
** free the entire array
*/

#include <stddef.h>
#include <stdlib.h>

void my_free_array(char **array)
{
    if (!array)
        return;

    for (int i = 0; array[i] != NULL; i += 1) {
        free(array[i]);
    }
    free(array);
    array = NULL;
}
