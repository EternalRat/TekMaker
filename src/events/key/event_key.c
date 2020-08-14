/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** event_handler
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void editor_key(tekmaker_t *tek)
{
    int key[] = {tek->key.right, tek->key.left, tek->key.jump, tek->key.down,
        tek->key.editor_right, tek->key.editor_left, sfKeyEscape};
    void (*func[])(tekmaker_t *) = {move_to_right, move_to_left, move_to_up,
        move_to_down, move_block_selection_right, move_block_selection_left,
        editor_pause};

    for (int i = 0; i != 7; i++)
        if (key[i] == tek->windows.event.key.code)
            func[i](tek);
}

void game_key(tekmaker_t *tek)
{
    int key[] = {tek->key.right, tek->key.left, tek->key.jump, sfKeyEscape,
        tek->key.fire};
    void (*func[])(tekmaker_t *) = {move_player_right, move_player_left,
        jump_player, evt_pause_menu, shooting_fire};

    for (int i = 0; i != 5; i++)
        if (key[i] == tek->windows.event.key.code)
            func[i](tek);
    sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
    sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
}

void list_map_key(tekmaker_t *tek)
{
    int key[] = {tek->key.right, tek->key.left, -1};
    void (*func[])(tekmaker_t *) = {move_to_right, move_to_left};

    for (int i = 0; key[i] != -1; i++)
        if (key[i] == tek->windows.event.key.code)
            func[i](tek);
}

void event_key(tekmaker_t *tek)
{
    int menu[] = {EDITOR, GAME, LIST_MAP, EDIT_MAP, EDITOR_PAUSE, -1};
    void (*func[])(tekmaker_t *) = {editor_key, game_key, list_map_key,
        list_map_key, event_editor_pause};

    for (int i = 0; menu[i] != -1; i++) {
        if (menu[i] == tek->states)
            func[i](tek);
    }
}