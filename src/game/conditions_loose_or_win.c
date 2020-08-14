/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** conditions_loose
*/

#include "tekmaker.h"

void check_if_dead(tekmaker_t *tek, map_e_t *block)
{
    if (block->id == 'C' && tek->game.player.power_up.godmode == false)
        tek->game.player.is_alive = 0;
}

int check_collision_with_ennemy(tekmaker_t *tek, sfVector2f player_pos)
{
    sfVector2f pos;

    for (enemy_t *enemy = tek->game.enemy; enemy; enemy = enemy->next) {
        pos = sfSprite_getPosition(enemy->sprite);
        if ((((pos.x < (player_pos.x)) && (pos.x + 50 > (player_pos.x)) &&
        (pos.y <= player_pos.y + 25) && (pos.y + 45 >= player_pos.y + 25))
        || ((pos.x < (player_pos.x + 50)) && (pos.x + 50 > (player_pos.x + 50))
        && (pos.y <= player_pos.y + 25) && (pos.y + 45 >= player_pos.y + 25)))
        && tek->game.player.power_up.godmode == false) {
            return (1);
        } else if ((((pos.x < (player_pos.x)) && (pos.x + 50 > (player_pos.x))
        && (pos.y <= player_pos.y + 25) && (pos.y + 45 >= player_pos.y + 25))
        || ((pos.x < (player_pos.x + 50)) && (pos.x + 50 > (player_pos.x + 50))
        && (pos.y <= player_pos.y + 25) && (pos.y + 45 >= player_pos.y + 25)))
        && tek->game.player.power_up.godmode == true) {
            enemy->pos = (sfVector2f){-5000, 10000};
            return (0);
        }
    }
    return (0);
}

int check_collision_with_end(tekmaker_t *tek, int value, sfVector2f player_pos)
{
    sfVector2f pos;

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x < (player_pos.x + value)) && (pos.x + 50 >
        (player_pos.x + value)) && (pos.y <= player_pos.y) && (pos.y + 45 >=
        player_pos.y)) || ((pos.x < (player_pos.x + value + 50)) && (pos.x + 50
        > (player_pos.x + value + 50)) && (pos.y <= player_pos.y) &&
        (pos.y + 45 >= player_pos.y)) || ((pos.x < (player_pos.x + value)) &&
        (pos.x + 50 > (player_pos.x + value)) && (pos.y <= (player_pos.y + 48))
        && (pos.y + 50 >= (player_pos.y + 48))) || ((pos.x < (player_pos.x +
        value + 50)) && (pos.x + 50 > (player_pos.x + value + 50)) && (pos.y <=
        (player_pos.y + 48)) && (pos.y + 50 >= (player_pos.y + 48)))) &&
        block->id == 'H') {
            return (1);
        }
    }
    return (0);
}

int check_collision_with_hurting_block(tekmaker_t *tek, int value,
sfVector2f player_pos)
{
    sfVector2f pos;

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x < (player_pos.x + value)) && (pos.x + 50 >
        (player_pos.x + value)) && (pos.y <= player_pos.y) && (pos.y + 45 >=
        player_pos.y)) || ((pos.x < (player_pos.x + value + 50)) && (pos.x + 50
        > (player_pos.x + value + 50)) && (pos.y <= player_pos.y) &&
        (pos.y + 45 >= player_pos.y)) || ((pos.x < (player_pos.x + value)) &&
        (pos.x + 50 > (player_pos.x + value)) && (pos.y <= (player_pos.y + 48))
        && (pos.y + 50 >= (player_pos.y + 48))) || ((pos.x < (player_pos.x +
        value + 50)) && (pos.x + 50 > (player_pos.x + value + 50)) && (pos.y <=
        (player_pos.y + 48)) && (pos.y + 50 >= (player_pos.y + 48)))) &&
        block->id == 'C' && tek->game.player.power_up.godmode == false) {
            return (1);
        }
    }
    return (0);
}

int check_collision_with_hurting_blocks(tekmaker_t *tek,
sfVector2f player_pos)
{
    sfVector2f pos;

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x <= (player_pos.x)) &&
        (pos.x + 50 >= (player_pos.x)) && (pos.y <= (player_pos.y + 55))
        && (pos.y + 50 >= (player_pos.y + 55))) || ((pos.x <= (player_pos.x
        + 50)) && (pos.x + 50 >= (player_pos.x + 50)) && (pos.y <=
        (player_pos.y + 55)) && (pos.y + 50 >= (player_pos.y + 55)))) &&
        block->id == 'C' && tek->game.player.power_up.godmode == false) {
            return (1);
        }
    }
    return (0);
}