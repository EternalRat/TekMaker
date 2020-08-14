/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** move_background
*/

#include "tekmaker.h"

void move_background(background_t *background, int state, float value)
{
    for (background_t *tmp = background; tmp; tmp = tmp->next) {
        if (state == EDITOR || state == GAME)
            tmp->rect.left += (int)value * tmp->speed;
        if (tmp->rect.left > 2560 / 2)
            tmp->rect.left = 0;
        else if (tmp->rect.left < 0)
            tmp->rect.left = 2560 / 2;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
}