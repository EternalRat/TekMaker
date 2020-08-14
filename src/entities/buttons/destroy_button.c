/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_button
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_buttons(button_t **elem, int count)
{
    button_t *todelete;

    if (elem == NULL)
        return;
    if (count > 1) {
        todelete = *elem;
        *elem = todelete->next;
        free(todelete);
    } else if (count == 1) {
        free(*elem);
        *elem = NULL;
    }
}

void destroy_button(button_t *btn)
{
    int count = count_button(btn);

    for (button_t *destroy = btn; destroy; destroy = destroy->next) {
        sfTexture_destroy(destroy->texture);
        sfSprite_destroy(destroy->sprite);
        sfFont_destroy(destroy->font);
        sfText_destroy(destroy->text);
    }
    for (; count != 0; count--)
        destroy_buttons(&btn, count);
}