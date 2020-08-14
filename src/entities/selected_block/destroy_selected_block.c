/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** destroy_selected_block
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_selected_block(selected_block_t *selected_block)
{
    sfSprite_destroy(selected_block->sprite);
    sfTexture_destroy(selected_block->texture);
}