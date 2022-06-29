/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** struct, enum and prototypes
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <stdbool.h>
    #include "my.h"

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct game_s {
    int nb_player;
    int nb_hole;
    int nb_box;
    int final_hole;
    bool win;
    int map_line;
    int map_col;
    char *buffer;
    char **map;
    char **map_saved;
    position_t pos;
} game_t;

/* INSTANCE */
int loop(game_t *game, char *argv[]);
int sokoban(char *argv[]);
/* INIT */
int init_game(game_t *game, char **argv);
void init_ncurses(void);
/* GAME STATE */
void check_if_box_on_hole(game_t *game);
bool check_victory(game_t *game);
/* MOVEMENT */
void move_up(game_t *game);
void move_down(game_t *game);
void move_left(game_t *game);
void move_right(game_t *game);
void get_player_position(game_t *game);
void move_player(game_t *game, int input, char *argv[]);
/* ERROR HANDLING */
int check_env(char *env[]);
int check_number_elem(game_t *game);
int check_arg(int const argc, char *argv[]);
/* MAP */
void print_map(game_t *game);
void resize_terminal(game_t *map);
int save_2d_map(game_t *game);
void get_map_col(game_t *game);
void get_map_line(game_t *game);
void reset_map(game_t *game, char *argv[]);
int create_2d_map(game_t *game, char *argv[]);
int check_is_map_valid(game_t *game, int y, int x);
/* MEMORY */
void free_elem(game_t *game);
char *open_read_file(const char *filepath);
int rules(void);

#endif/* !SOKOBAN_H_ */
