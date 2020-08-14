/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** create_selected_block.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void check_scaling(sfIntRect intrect, float x, float y,
selected_block_t *selected_block)
{
    if (x == y)
        sfSprite_scale(selected_block->selected_block_sprite,
        (sfVector2f){50/x, 50/y});
    else if (x == 2*y) {
        sfSprite_scale(selected_block->selected_block_sprite,
        (sfVector2f){100/x, 50/y});
        sfSprite_setTextureRect(selected_block->selected_block_sprite, intrect);
    }
}

void create_selected_block(selected_block_t *selected_block, \
sfTexture *texture, char id)
{
    sfIntRect rect = {0, 0, 50, 50};
    sfIntRect intrect;
    float x = 0.00;
    float y = 0.00;

    if (selected_block->selected_block_sprite)
        sfSprite_destroy(selected_block->selected_block_sprite);
    if (selected_block->selected_block_texture)
        sfTexture_destroy(selected_block->selected_block_texture);
    selected_block->selected_block_texture = sfTexture_copy(texture);
    x = (float)sfTexture_getSize(selected_block->selected_block_texture).x;
    y = (float)sfTexture_getSize(selected_block->selected_block_texture).y;
    intrect = (sfIntRect){rect.left, rect.top, x/2, y};
    selected_block->selected_block_sprite = sfSprite_create();
    selected_block->selected_block_id = id;
    sfSprite_setTexture(selected_block->selected_block_sprite,
    selected_block->selected_block_texture, sfTrue);
    if (id == 'K' || id == 'L')
        sfSprite_setTextureRect(selected_block->selected_block_sprite,
        (sfIntRect){0, 0, 50, 50});
    check_scaling(intrect, x, y, selected_block);
}