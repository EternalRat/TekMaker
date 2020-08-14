/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** move_with_player
*/

#include "tekmaker.h"

int check_colision_enemy(map_e_t *map, int value, sfVector2f enemy_pos)
{
    sfVector2f pos;

    for (map_e_t *block = map; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < (enemy_pos.x + value)) && (pos.x + 50 >
        (enemy_pos.x + value)) && (pos.y <= enemy_pos.y + 25) && (pos.y + 45 >=
        enemy_pos.y + 25)) || ((pos.x < (enemy_pos.x + value + 50)) && (pos.x +
        50 > (enemy_pos.x + value + 50)) && (pos.y <= enemy_pos.y + 25) &&
        (pos.y + 45 >= enemy_pos.y + 25))) {
            return (1);
        }
    }
    return (0);
}

int is_on_block(map_e_t *map, sfVector2f enemy_pos)
{
    sfVector2f pos;

    for (map_e_t *block = map; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < enemy_pos.x + 2) && (pos.x + 50 > enemy_pos.x + 2)
        && (pos.y <= (enemy_pos.y + 48)) && (pos.y + 50 >= (enemy_pos.y + 50)))
        || ((pos.x < (enemy_pos.x + 48)) && (pos.x + 50 > (enemy_pos.x + 48))
        && (pos.y <= (enemy_pos.y + 48)) && (pos.y + 50 >= (enemy_pos.y +
        50)))) {
            return (1);
        }
    }
    return (0);
}

void do_anim(enemy_t **tmp, int *neg_or_pos, map_e_t *map)
{
    if (check_colision_enemy(map, 10 * (*neg_or_pos),
    sfSprite_getPosition((*tmp)->sprite)) && (*neg_or_pos) == 1) {
        (*tmp)->pos.x += 20;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
        (*neg_or_pos) *= -1;
    } else if (check_colision_enemy(map, 10 * (*neg_or_pos),
    sfSprite_getPosition((*tmp)->sprite))) {
        (*tmp)->pos.x -= 20;
        sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
        (*neg_or_pos) *= -1;
    }
    if ((*tmp)->rect.left >= (*tmp)->end)
        (*tmp)->rect.left = (*tmp)->start;
    else if ((*tmp)->rect.left <= 0)
        (*tmp)->rect.left = (*tmp)->start - 50;
}

void anim_enemy(enemy_t **tmp, map_e_t *map, int move)
{
    int value = 50;
    static int neg_or_pos = 1;

    do_anim(tmp, &neg_or_pos, map);
    sfSprite_setTextureRect((*tmp)->sprite, (*tmp)->rect);
    if ((*tmp)->end == 450) {
        (*tmp)->rect.left += value * neg_or_pos;
        (*tmp)->pos.x -= neg_or_pos * move * (*tmp)->speed;
    } else {
        (*tmp)->rect.left += value;
        (*tmp)->pos.x -= move * (*tmp)->speed;
    }
    sfSprite_setPosition((*tmp)->sprite, (*tmp)->pos);
}

void move_enemy(tekmaker_t *tek, int value)
{
    for (enemy_t *tmp = tek->game.enemy; tmp; tmp = tmp->next) {
        anim_enemy(&tmp, tek->editor.map_e, value);
        sfRenderWindow_drawSprite(tek->windows.window, tmp->sprite, NULL);
    }
}