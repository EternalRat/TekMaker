/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** init_enemy
*/

#include "enemy.h"
#include "tekmaker.h"
#include <stdlib.h>

void display_enemy(tekmaker_t *tek, int value)
{
    for (enemy_t *tmp = tek->game.enemy; tmp; tmp = tmp->next) {
        if (is_enemy_visible(tmp, tek->windows.settings))
            animation_enemy(&tmp, tek->editor.map_e, tek->game.settings.gravity,
            value);
        sfRenderWindow_drawSprite(tek->windows.window, tmp->sprite, NULL);
    }
}

static void set_sprite(enemy_t *enemy, sfTexture *texture, sfVector2i pos,
int left)
{
    enemy->sprite = sfSprite_create();
    enemy->texture = sfTexture_copy(texture);
    enemy->rect = (sfIntRect){left, 0, 50, 50};
    enemy->pos = (sfVector2f){pos.x - (pos.x % 50), pos.y - (pos.y % 50)};
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
}

enemy_t *init_enemy(enemy_t **enemy, sfTexture *texture, sfVector2i pos,
int *stat)
{
    enemy_t *enemy_tmp = malloc(sizeof(enemy_t));
    enemy_t *tmp;

    set_sprite(enemy_tmp, texture, pos, stat[2]);
    enemy_tmp->clock = sfClock_create();
    enemy_tmp->speed = stat[0];
    enemy_tmp->hp = stat[1];
    if (stat[2] == 250) {
        enemy_tmp->end = 450;
        enemy_tmp->start = stat[2];
    } else {
        enemy_tmp->end = 300;
        enemy_tmp->start = 50;
    }
    enemy_tmp->next = NULL;
    if ((*enemy) == NULL)
        return (enemy_tmp);
    for (tmp = (*enemy); tmp->next; tmp = tmp->next);
    tmp->next = enemy_tmp;
    return ((*enemy));
}