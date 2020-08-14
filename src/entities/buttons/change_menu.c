/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** change_menu
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void go_to_editor_menu(tekmaker_t *tek)
{
    tek->old_states = tek->states;
    tek->states = EDITOR_MENU;
}

void go_to_list(tekmaker_t *tek)
{
    tek->old_states = tek->states;
    tek->states = CREATE_LIST;
}

void go_to_editor(tekmaker_t *tek)
{
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    map_create(tek->windows.settings, &tek->map);
    tek->old_states = tek->states;
    tek->states = EDITOR;
}

void go_to_edit_map(tekmaker_t *tek)
{
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    tek->old_states = tek->states;
    tek->states = CREATE_LIST;
}

void go_back(tekmaker_t *tek)
{
    if (tek->states != tek->old_states)
        tek->states = tek->old_states;
    else
        tek->states = MENU;
}