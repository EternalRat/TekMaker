/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_image
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_images(image_t **elem, int count)
{
    image_t *todelete;

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

void destroy_image(image_t *img)
{
    int count = count_image(img);

    for (image_t *destroy = img; destroy; destroy = destroy->next) {
        sfTexture_destroy(destroy->texture);
        sfSprite_destroy(destroy->sprite);
    }
    for (; count != 0; count--)
        destroy_images(&img, count);
}