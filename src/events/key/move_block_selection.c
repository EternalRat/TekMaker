/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** move_block_selection
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void move_block_selection_right(tekmaker_t *tek)
{
    sfVector2f pos;

    if ((tek->editor.select_block_pos +
        (tek->windows.settings.width / 100)) >=
        count_image(tek->editor.image))
        return;
    for (image_t *tmp = tek->editor.image; tmp != NULL; tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->sprite);
        sfSprite_setPosition(tmp->sprite,
        (sfVector2f){pos.x - 100, pos.y});
    }
    tek->editor.select_block_pos++;
}

void move_block_selection_left(tekmaker_t *tek)
{
    sfVector2f pos;


    if (tek->editor.select_block_pos <= 0)
        return;
    for (image_t *tmp = tek->editor.image; tmp != NULL; tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->sprite);
        sfSprite_setPosition(tmp->sprite,
        (sfVector2f){pos.x + 100, pos.y});
    }
    tek->editor.select_block_pos--;
}