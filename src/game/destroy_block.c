/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_block
*/

#include "tekmaker.h"

void check_if_destructible(map_e_t *block)
{
    char *id = "45";

    for (int i = 0; id[i]; i++) {
        if (id[i] == block->id) {
            sfSprite_setPosition(block->sprite, (sfVector2f){-50000, -50});
            break;
        }
    }
}