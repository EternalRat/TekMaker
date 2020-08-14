/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** display_image
*/

#include "tekmaker.h"

void image_display(image_t *images, sfRenderWindow *windows)
{
    for (image_t *image = images; image; image = image->next) {
        sfRenderWindow_drawSprite(windows, image->sprite, NULL);
    }
}