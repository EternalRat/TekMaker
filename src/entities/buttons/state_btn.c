/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** state_btn
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void event_btn_state(sfVector2i m_pos, button_t *btn)
{
    sfVector2f pos = sfSprite_getPosition(btn->sprite);

    if (m_pos.x >= pos.x && m_pos.x <= pos.x + 400 &&
    m_pos.y >= pos.y && m_pos.y <= pos.y + 80) {
        sfSprite_setTextureRect(btn->sprite, (sfIntRect){0, 40, 200, 20});
    } else {
        sfSprite_setTextureRect(btn->sprite, (sfIntRect){0, 20, 200, 20});
    }
}