/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** check_collision
*/

#include "tekmaker.h"

int check_collision_jump_up(tekmaker_t *tek)
{
    sfVector2f pos;
    sfVector2f p_pos = sfSprite_getPosition(tek->game.player.sprite);

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < p_pos.x) &&
        (pos.x + 50 > p_pos.x) && (pos.y < (p_pos.y + tek->game.player.jump))
        && (pos.y + 50 > (p_pos.y + tek->game.player.jump))) || ((pos.x <
        (p_pos.x + 48)) && (pos.x + 50 > (p_pos.x + 48)) && (pos.y <= (p_pos.y
        - tek->game.player.jump)) && (pos.y + 50 >= (p_pos.y -
        tek->game.player.jump)))) {
            check_if_dead(tek, block);
            check_if_destructible(block);
            check_for_bonus(tek, block);
            return (1);
        }
    }
    return (0);
}

int check_collision_jump_down(tekmaker_t *tek)
{
    sfVector2f pos;
    sfVector2f p_pos = sfSprite_getPosition(tek->game.player.sprite);

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < p_pos.x + 2) && (pos.x + 50 > p_pos.x + 2)
        && (pos.y <= (p_pos.y + 45 - tek->game.player.jump)) && (pos.y + 50
        >= (p_pos.y + 45 - tek->game.player.jump))) || ((pos.x < (p_pos.x +
        48)) && (pos.x + 50 > (p_pos.x + 48)) && (pos.y <= (p_pos.y + 45 -
        tek->game.player.jump)) && (pos.y + 50 >= (p_pos.y + 45 -
        tek->game.player.jump)))) {
            return (1);
        }
    }
    return (0);
}

int check_if_good_block_is_hit_down(tekmaker_t *tek, char c)
{
    sfVector2f pos;
    sfVector2f p_pos = sfSprite_getPosition(tek->game.player.sprite);

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x < p_pos.x + 2) &&
        (pos.x + 50 > p_pos.x + 2) && (pos.y <= (p_pos.y + 50))
        && (pos.y + 50 >= (p_pos.y + 50))) || ((pos.x < (p_pos.x
        + 48)) && (pos.x + 50 > (p_pos.x + 48)) && (pos.y <=
        (p_pos.y + 50)) && (pos.y + 50 >= (p_pos.y + 50)))) && block->id == c) {
            return (1);
        }
    }
    return (0);
}

int check_if_a_block_is_hit_down(tekmaker_t *tek)
{
    sfVector2f pos;
    sfVector2f p_pos = sfSprite_getPosition(tek->game.player.sprite);

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if ((((pos.x < p_pos.x + 2) &&
        (pos.x + 50 > p_pos.x + 2) && (pos.y <= (p_pos.y + 48))
        && (pos.y + 50 >= (p_pos.y + 48))) || ((pos.x < (p_pos.x
        + 48)) && (pos.x + 50 > (p_pos.x + 48)) && (pos.y <=
        (p_pos.y + 48)) && (pos.y + 50 >= (p_pos.y + 48))))) {
            return (1);
        }
    }
    return (0);
}

int check_if_a_block_is_hit_up(tekmaker_t *tek)
{
    sfVector2f pos;
    sfVector2f p_pos = sfSprite_getPosition(tek->game.player.sprite);

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < p_pos.x) &&
        (pos.x + 50 > p_pos.x) && (pos.y < (p_pos.y))
        && (pos.y + 50 > (p_pos.y))) || ((pos.x < p_pos.x + 48) &&
        (pos.x + 50 > p_pos.x + 48) && (pos.y < (p_pos.y))
        && (pos.y + 50 > (p_pos.y)))) {
            return (1);
        }
    }
    return (0);
}