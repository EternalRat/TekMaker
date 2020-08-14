/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_fireball
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_fireball(fireball_t **mob, int count)
{
    fireball_t *todelete;

    if ((*mob) == NULL)
        return;
    if (count > 1) {
        todelete = *mob;
        *mob = todelete->next;
        free(todelete);
    } else if (count == 1) {
        free(*mob);
        *mob = NULL;
    }
}

void destroy_all_fireball(fireball_t *fireball)
{
    int count = count_fireball(fireball);

    for (fireball_t *destroy = fireball; destroy; destroy = destroy->next) {
        sfTexture_destroy(destroy->texture);
        sfSprite_destroy(destroy->sprite);
    }
    for (; count != 0; count--)
        destroy_fireball(&fireball, count);
}