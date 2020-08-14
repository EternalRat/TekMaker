/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_image
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_blocks(map_e_t **map, int count)
{
    map_e_t *todelete;

    if (map == NULL)
        return;
    if (count > 1) {
        todelete = *map;
        *map = todelete->next;
        free(todelete);
    } else if (count == 1) {
        free(*map);
        *map = NULL;
    }
}

void destroy_map_block(map_e_t *map)
{
    int count = count_block(map);

    for (map_e_t *destroy = map; destroy; destroy = destroy->next) {
        sfTexture_destroy(destroy->texture);
        sfSprite_destroy(destroy->sprite);
    }
    for (; count != 0; count--)
        destroy_blocks(&map, count);
}