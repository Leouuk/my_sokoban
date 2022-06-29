/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** ncurse
*/

#include <curses.h>
#include "sokoban.h"

void init_ncurses(void)
{
    initscr();
    raw();
    curs_set(0);
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}
