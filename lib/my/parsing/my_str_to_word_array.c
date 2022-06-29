/*
** EPITECH PROJECT, 2022
** minishell project header
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>
#include "../my.h"

static char *my_convert_into_space(char *str, int delim)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t' || str[i] == '\n') {
            str[i] = delim;
        }
        i += 1;
    }
    return str;
}

static int my_count_words(char *str, int delim)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] == delim) {
        i += 1;
    }
    while (str[i] != '\0') {
        if (str[i] == delim && str[i + 1] >= '!' && str[i + 1] <= '~') {
            nb_words += 1;
        }
        i += 1;
    }
    return nb_words + 1;
}

static char **my_create_array(char **array, char *str, int pos, int delim)
{
    int i = 0;
    int nb_char = 0;

    while (str[i] == delim)
        i += 1;
    while (str[i + 1] != delim && str[i] != '\0') {
        nb_char += 1;
        i += 1;
    }
    array[pos] = malloc(sizeof(char) * (nb_char + 2));
    if (!array)
        return NULL;
    return array;
}

static char **my_fill_array(char **array, char *str, int nb_words, int delim)
{
    int i = 0;
    int x = 0;

    if (!array || !str)
        return NULL;
    for (int y = 0; str[i] != '\0' || str[i + 1] == '\0'; y += 1) {
        i = my_skip_space(str, i);
        while (str[i] != delim && str[i] != '\0') {
            array[y][x] = str[i];
            i += 1;
            x += 1;
        }
        i += 1;
        array[y][x] = '\0';
        x = 0;
        if (y == (nb_words - 1))
            return array;
    }
    return array;
}

char **my_str_to_word_array(char *str, int delim)
{
    int nb_words = 0;
    char **array = NULL;

    if (!str)
        return NULL;
    str = my_convert_into_space(str, delim);
    nb_words = my_count_words(str, delim);
    if (nb_words <= 0)
        return NULL;
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (!array)
        return NULL;
    array[nb_words] = NULL;
    for (int i = 0; i < nb_words; i += 1) {
        array = my_create_array(array, str, i, delim);
    }
    array = my_fill_array(array, str, nb_words, delim);
    return array;
}
