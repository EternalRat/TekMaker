/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** check_collision_enemy
*/

#include "tekmaker.h"

int check_collision_enemy(map_e_t *map, int value, sfVector2f enemy_pos)
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

int is_on_a_block(map_e_t *map, sfVector2f enemy_pos)
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

int check_if_a_block_is_hit_down_enemy(enemy_t *tmp, map_e_t *map_e)
{
    sfVector2f pos;
    sfVector2f e_pos = sfSprite_getPosition(tmp->sprite);

    for (map_e_t *block = map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x < e_pos.x + 2) &&
        (pos.x + 50 > e_pos.x + 2) && (pos.y <= (e_pos.y + 46))
        && (pos.y + 50 >= (e_pos.y + 46))) || ((pos.x < (e_pos.x
        + 48)) && (pos.x + 50 > (e_pos.x + 48)) && (pos.y <=
        (e_pos.y + 46)) && (pos.y + 50 >= (e_pos.y + 46))))) {
            return (1);
        }
    }
    return (0);
}
