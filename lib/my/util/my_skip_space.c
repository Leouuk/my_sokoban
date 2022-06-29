/*
** EPITECH PROJECT, 2021
** my_skip_space
** File description:
** Skip spaces
*/

int my_skip_space(char const *str, int i)
{
    while (str[i] == ' ')
        i += 1;
    return i;
}
