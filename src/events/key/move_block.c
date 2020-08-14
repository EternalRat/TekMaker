/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** move_block
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void move_cam(int state, void *params, int value_x, int value_y)
{
    sfVector2f pos;
    sfVector2f pos_text;

    if (state == EDITOR || state == GAME) {
        for (map_e_t *tmp = params; tmp != NULL; tmp = tmp->next) {
            pos = sfSprite_getPosition(tmp->sprite);
            sfSprite_setPosition(tmp->sprite,
            (sfVector2f){pos.x + value_x, pos.y + value_y});
        }
        return;
    } else if (state == LIST_MAP || state == EDIT_MAP) {
        for (list_files_t *tmp = params; tmp != NULL; tmp = tmp->next) {
            pos = sfSprite_getPosition(tmp->sprite);
            pos_text = sfText_getPosition(tmp->text);
            sfText_setPosition(tmp->text,
            (sfVector2f){pos_text.x + value_x, pos_text.y});
            sfSprite_setPosition(tmp->sprite,
            (sfVector2f){pos.x + value_x, pos.y});
        }
    }
}

void move_to_right(tekmaker_t *tek)
{
    int value[] = {tek->windows.settings.width * (-1),
        tek->windows.settings.width * (-1), 50 * (-1)};
    void(*params[]) = {tek->files.files, tek->files.files,
        tek->editor.map_e};
    int states[] = {LIST_MAP, EDIT_MAP, EDITOR, -1};

    if ((tek->editor.map_pos + tek->windows.settings.width) / 50 >=
        tek->windows.settings.x_limit)
        return;
    for (int i = 0; states[i] != -1; i++) {
        if (tek->states == states[i]) {
            move_cam(states[i], params[i], value[i], 0);
            tek->editor.map_pos += 50;
        }
    }
    move_background(tek->editor.background, tek->states, 10);
}

void move_to_left(tekmaker_t *tek)
{
    int value[] = {tek->windows.settings.width,
        tek->windows.settings.width, 50};
    void(*params[]) = {tek->files.files, tek->files.files,
        tek->editor.map_e};
    int states[] = {LIST_MAP, EDIT_MAP, EDITOR, -1};

    if (tek->editor.map_pos <= 0)
        return;
    for (int i = 0; states[i] != -1; i++) {
        if (tek->states == states[i]) {
            move_cam(states[i], params[i], value[i], 0);
            tek->editor.map_pos -= 50;
        }
    }
    move_background(tek->editor.background, tek->states, -10);
}

void move_to_up(tekmaker_t *tek)
{
    int value[] = {tek->windows.settings.height,
        tek->windows.settings.height, 50};
    void(*params[]) = {tek->files.files, tek->files.files,
        tek->editor.map_e};
    int states[] = {LIST_MAP, EDIT_MAP, EDITOR, -1};

    if ((tek->editor.map_pos_y + tek->windows.settings.height) / 50 >=
        tek->windows.settings.y_limit)
        return;
    for (int i = 0; states[i] != -1; i++) {
        if (tek->states == states[i]) {
            move_cam(states[i], params[i], 0, value[i]);
            tek->editor.map_pos_y += 50;
        }
    }
}

void move_to_down(tekmaker_t *tek)
{
    int value[] = {tek->windows.settings.height * (-1),
        tek->windows.settings.height * (-1), 50 * (-1)};
    void(*params[]) = {tek->files.files, tek->files.files,
        tek->editor.map_e, NULL};
    int states[] = {LIST_MAP, EDIT_MAP, EDITOR, -1};

    if (tek->editor.map_pos_y <= 0)
        return;
    for (int i = 0; states[i] != -1; i++) {
        if (tek->states == states[i]) {
            move_cam(states[i], params[i], 0, value[i]);
            tek->editor.map_pos_y -= 50;
        }
    }
}