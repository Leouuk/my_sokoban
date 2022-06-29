##
## EPITECH PROJECT, 2021
## Makefile for sokoban
## File description:
## Root Makefile project
##

CC			=	gcc									\

SRC_MAIN	=	src/main.c							\

SRC_UTIL	=	src/util/help.c						\
				src/util/manage_file.c

SRC_ERROR	=	src/error_handling/check_error.c	\
				src/error_handling/free_memory.c	\

SRC_INSTANCE=	src/instance/loop.c					\
				src/instance/sokoban.c

SRC_MAP		=	src/map/create_map.c				\
				src/map/check_map_validity.c		\
				src/map/get_player_pos.c			\
				src/map/map_dimensions.c			\
				src/map/print_map.c					\
				src/map/reset_map.c					\
				src/map/save_map.c

SRC_MOVE	=	src/movement/move_player.c			\
				src/movement/down.c					\
				src/movement/left.c					\
				src/movement/right.c				\
				src/movement/up.c

SRC_GAME	=	src/game/analyse_game_state.c		\
				src/game/replace_hole.c				\
				src/game/resize_terminal.c

SRC_INIT	=	src/init/game.c						\
				src/init/ncurse.c

SRC			=	$(SRC_MAIN) 						\
				$(SRC_INSTANCE)						\
				$(SRC_UTIL)							\
				$(SRC_INIT)							\
				$(SRC_ERROR)						\
				$(SRC_MAP)							\
				$(SRC_MOVE)							\
				$(SRC_GAME)

OBJ			=	$(SRC:.c=.o)

SRC_TEST	=	tests/test_sokoban.c

OBJ_TEST	=	$(SRC_TEST:.c=.o)

OBJ_GCNO	=	$(SRC:.c=.gcno) $(SRC_MAIN:.c=.gcno) $(SRC_TEST:.c=.gcno)

OBJ_GCDA	=	$(SRC:.c=.gcda) $(SRC_MAIN:.c=.gcda) $(SRC_TEST:.c=.gcda)

EXE_TEST	=	tests_run

CFLAGS		=	-Wextra -Wall
CDFLAGS		=	-lncurses
LIBFLAGS	=	-L./lib/my -lmy
CPPFLAGS	=	-I./include

NAME		=	my_sokoban

$(NAME):	$(OBJ)
	make -C./lib/my
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIBFLAGS) $(CDFLAGS)

unit_tests:	LDLIBS += -lcriterion --coverage
unit_tests:	CFLAGS += --coverage

unit_tests: $(OBJ) $(OBJ_TEST)
		make -C./lib/my
		gcc -o $(EXE_TEST) $(OBJ_TEST) $(OBJ) $(LDLIBS) $(LIBFLAGS)

tests_run: unit_tests
		./$(EXE_TEST) --verbose

all:	$(NAME)

debug: fclean
debug: CFLAGS += -ggdb3
debug: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)
	find -name *.# -delete
	find -name *.~ -delete
	find -name *.tmp -delete

fclean:	clean
	make fclean -C ./lib/my
	$(RM) $(NAME) $(EXE_TEST)

re:	fclean all

.PHONY: all clean fclean re debug unit_tests
