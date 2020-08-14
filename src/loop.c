/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** menu
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void loop(tekmaker_t *tek)
{
    void (*funct[])(tekmaker_t *) = {menu_start, map_editor,
        create_list, list_map, map_editor_menu, select_map_to_edit,
        play_game, editor_pause_loop, pause_menu, NULL};
    int menu[] = {MENU, EDITOR, CREATE_LIST, LIST_MAP, EDITOR_MENU, EDIT_MAP,
        GAME, EDITOR_PAUSE, GAME_PAUSE};

    while (sfRenderWindow_pollEvent(tek->windows.window,
        &tek->windows.event))
        event_handler(tek);
    for (int i = 0; funct[i]; i++) {
        if (menu[i] == tek->states) {
            funct[i](tek);
            break;
        }
    }
}