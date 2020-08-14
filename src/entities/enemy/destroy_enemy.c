/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy_enemy
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_enemy(enemy_t **mob, int count)
{
    enemy_t *todelete;

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

void destroy_all_mob(enemy_t *enemy)
{
    int count = count_enemy(enemy);

    for (enemy_t *destroy = enemy; destroy; destroy = destroy->next) {
        sfTexture_destroy(destroy->texture);
        sfSprite_destroy(destroy->sprite);
    }
    for (; count != 0; count--)
        destroy_enemy(&enemy, count);
}