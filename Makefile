##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

RM = rm -f

CC = gcc

NAME	=	tekmaker

SRC	=	src/map_editor/editor_pause/editor_pause.c    \
		src/map_editor/editor_pause/event_editor_pause.c \
		src/map_editor/editor_pause/action_button.c \
		src/map_editor/map_editor.c	\
		src/map_editor/create_map_editor.c	\
		src/events/mouse/mouse_event.c	\
		src/events/mouse/update_block.c	\
		src/events/event_handler.c	\
		src/events/key/event_key.c	\
		src/events/key/move_block.c	\
		src/events/key/move_background.c	\
		src/events/key/move_block_selection.c	\
		src/display/menu_display.c	\
		src/display/display_list_map.c	\
		src/entities/buttons/create_button.c	\
		src/entities/buttons/change_menu.c	\
		src/entities/buttons/destroy_button.c	\
		src/entities/buttons/count_button.c	\
		src/entities/buttons/state_btn.c	\
		src/entities/buttons/exit_game.c	\
		src/entities/enemy/init_enemy.c	\
		src/entities/enemy/check_collision_enemy.c	\
		src/entities/enemy/count_mob.c	\
		src/entities/enemy/destroy_enemy.c	\
		src/entities/enemy/animation_and_check.c	\
		src/entities/enemy/move_with_player.c	\
		src/entities/window/create_windows.c	\
		src/entities/background/init_background.c	\
		src/entities/image/init_image.c	\
		src/entities/image/count_image.c	\
		src/entities/image/display_image.c	\
		src/entities/image/destroy_image.c	\
		src/entities/list_map/fill_list_map.c	\
		src/entities/list_map/fill_list.c	\
		src/entities/list_map/list_map_state.c	\
		src/entities/list_map/free_list.c	\
		src/entities/create_map/check_map.c	\
		src/entities/create_map/init_map.c	\
		src/entities/create_map/place_block.c	\
		src/entities/create_map/destroy_block.c	\
		src/entities/create_map/count_block.c	\
		src/entities/create_map/create_blocks.c \
		src/entities/selected_block/create_selected_block.c	\
		src/entities/character/init_player.c	\
		src/entities/fireball/count_fireball.c \
		src/entities/fireball/destroy_fireball.c \
		src/entities/fireball/init_fireball.c \
		src/entities/init_game.c \
		src/entities/init.c	\
		src/states/choose_states.c \
		src/parser/key/parser_key.c	\
		src/parser/settings/parser_settings.c	\
		src/parser/texture/parser_texture.c	\
		src/parser/game/game_parser.c	\
		src/parser/str_to_wordarray.c	\
		src/parser/parser.c \
		src/parser/map/parser_map.c \
		src/parser/map/map_modify.c \
		src/game/manage_bonus.c \
		src/game/destroy_block.c \
		src/game/win_or_loose.c \
		src/game/conditions_loose_or_win.c \
		src/game/bonus.c \
		src/game/pause_menu.c \
		src/game/jump_player.c \
		src/game/play_game.c \
		src/game/move_player.c \
		src/game/check_collision.c \
		src/loop.c	\
		src/destroy.c	\
		src/main.c	\

OBJ	= 	$(SRC:.c=.o)

CFLAGS	=	-I include 			\
		-W -Wall -Wshadow -Wextra	\

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

dbg: CFLAGS += -g
dbg: fclean
dbg: all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

tests_run:
		@make -sC ./tests
		./tests/unit_test

tests_fclean:
		make fclean -C tests

re: fclean all

.PHONY: clean fclean re all tests_run tests_fclean dbg
