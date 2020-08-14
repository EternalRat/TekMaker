/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** list_map_state
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void event_image(list_files_t *files, sfRenderWindow *window)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfSprite_getPosition(files->sprite);

    if (m_pos.x >= pos.x && m_pos.x <= pos.x + 200 &&
    m_pos.y >= pos.y && m_pos.y <= pos.y + 100) {
        sfText_setColor(files->text, (sfColor){255, 185, 0, 255});
        return;
    } else {
        sfText_setColor(files->text, (sfColor){255, 255, 255, 255});
        return;
    }
}