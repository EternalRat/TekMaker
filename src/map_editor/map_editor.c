/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** map_editor
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void display_block_to_place(sfRenderWindow *windows, sfSprite *selected_block)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(windows);

    if (selected_block == NULL)
        return;
    sfSprite_setPosition(selected_block,
    (sfVector2f){mouse_pos.x - 25, mouse_pos.y - 25});
    sfRenderWindow_drawSprite(windows, selected_block, NULL);
}

void map_editor(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_background(tek->editor.background, tek->windows.window);
    image_display(tek->editor.image, tek->windows.window);
    map_display(tek->editor.map_e, tek->windows, tek->states);
    display_block_to_place(tek->windows.window,
    tek->selected_block.selected_block_sprite);
    sfRenderWindow_display(tek->windows.window);
}

void select_map_to_edit(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_list(tek->files, tek->windows);
    sfRenderWindow_display(tek->windows.window);
}