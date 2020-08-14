/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_map
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void map_display(map_e_t *maps, windows_t window, int state)
{
    for (map_e_t *map = maps; map; map = map->next) {
        if (state == EDITOR && sfSprite_getPosition(map->sprite).y >=
            window.settings.height - 125)
            continue;
        sfRenderWindow_drawSprite(window.window, map->sprite, NULL);
    }
}

static void set_sprite(map_e_t *map, sfVector2i pos, sfTexture *texture)
{
    float x = 0.00;
    float y = 0.00;

    map->sprite = sfSprite_create();
    map->texture = sfTexture_copy(texture);
    x = (float)sfTexture_getSize(map->texture).x;
    y = (float)sfTexture_getSize(map->texture).y;
    map->intrect = (sfIntRect){0, 0, x/2, y};
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    if (x == y)
        sfSprite_scale(map->sprite, (sfVector2f){50/x, 50/y});
    else if (x == 2*y) {
        sfSprite_scale(map->sprite, (sfVector2f){100/x, 50/y});
        sfSprite_setTextureRect(map->sprite, map->intrect);
    } else {
        sfSprite_setTextureRect(map->sprite, (sfIntRect){0, 0, 50, 50});
    }
    sfSprite_setPosition(map->sprite,
    (sfVector2f){pos.x - (pos.x % 50), pos.y - (pos.y % 50)});
}

map_e_t *create_map_block(map_e_t **map, sfVector2i pos,
sfTexture *texture, char id)
{
    map_e_t *map_tmp = malloc(sizeof(map_e_t));
    map_e_t *tmp;

    if (!map)
        return (NULL);
    set_sprite(map_tmp, pos, texture);
    map_tmp->id = id;
    map_tmp->next = NULL;
    if (!map_tmp->sprite)
        exit(84);
    if (*map == NULL)
        return (map_tmp);
    tmp = *map;
    for (; tmp->next; tmp = tmp->next);
    tmp->next = map_tmp;
    return (*map);
}