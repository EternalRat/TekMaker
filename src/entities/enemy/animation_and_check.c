/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** animation_and_check
*/

#include "tekmaker.h"

int is_enemy_visible(enemy_t *tmp, settings_t setting)
{
    if (tmp->pos.x + 60 <= setting.width && tmp->pos.x + 60 >= 0 &&
    tmp->pos.y <= setting.height && tmp->pos.y >= 0) {
        return (1);
    }
    return (0);
}

void do_animation(enemy_t **tmp, int *neg_or_pos, map_e_t *map)
{
    if (check_collision_enemy(map, 10 * (*neg_or_pos),
    sfSprite_getPosition((*tmp)->sprite)) && (*neg_or_pos) == 1) {
        (*tmp)->pos.x += 20;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
        (*neg_or_pos) *= -1;
    } else if (check_collision_enemy(map, 10 * (*neg_or_pos),
    sfSprite_getPosition((*tmp)->sprite))) {
        (*tmp)->pos.x -= 20;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
        (*neg_or_pos) *= -1;
    }
    if ((*tmp)->rect.left >= (*tmp)->end)
        (*tmp)->rect.left = (*tmp)->start;
    else if ((*tmp)->rect.left <= 0) {
        (*tmp)->rect.left = (*tmp)->start - 50;
    }
    if (check_if_a_block_is_hit_down_enemy((*tmp), map)) {
        (*tmp)->pos.y -= 1;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
    }
}

void animation_enemy(enemy_t **tmp, map_e_t *map, int gravity, int move)
{
    int value = 50;
    static int neg_or_pos = 1;

    while (sfTime_asMilliseconds(sfClock_getElapsedTime((*tmp)->clock)) > 70) {
        do_animation(tmp, &neg_or_pos, map);
        sfSprite_setTextureRect((*tmp)->sprite, (*tmp)->rect);
        sfClock_restart((*tmp)->clock);
        if ((*tmp)->end == 450) {
            (*tmp)->rect.left += value * neg_or_pos;
            (*tmp)->pos.x -= neg_or_pos * move * (*tmp)->speed;
        } else {
            (*tmp)->rect.left += value;
            (*tmp)->pos.x -= move * (*tmp)->speed;
        }
        if (!is_on_a_block(map, sfSprite_getPosition((*tmp)->sprite)) &&
            (*tmp)->end == 450)
            (*tmp)->pos.y += 150 / gravity;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
    }
}