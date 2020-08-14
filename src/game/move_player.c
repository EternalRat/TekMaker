/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** move_player.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int check_collision(tekmaker_t *tek, int value, sfVector2f player_pos)
{
    sfVector2f pos;

    for (map_e_t *block = tek->editor.map_e; block; block = block->next) {
        pos = sfSprite_getPosition(block->sprite);
        if (((pos.x < (player_pos.x + value)) && (pos.x + 50 >
        (player_pos.x + value)) && (pos.y <= player_pos.y) && (pos.y + 45 >=
        player_pos.y)) || ((pos.x < (player_pos.x + value + 50)) && (pos.x + 50
        > (player_pos.x + value + 50)) && (pos.y <= player_pos.y) &&
        (pos.y + 45 >= player_pos.y)) || ((pos.x < (player_pos.x + value)) &&
        (pos.x + 50 > (player_pos.x + value)) && (pos.y <= (player_pos.y + 48))
        && (pos.y + 50 >= (player_pos.y + 48))) || ((pos.x < (player_pos.x +
        value + 50)) && (pos.x + 50 > (player_pos.x + value + 50)) && (pos.y <=
        (player_pos.y + 48)) && (pos.y + 50 >= (player_pos.y + 48)))) {
            return (1);
        }
    }
    return (0);
}

void move_player_right(tekmaker_t *tek)
{
    if (check_collision(tek, 10, sfSprite_getPosition(tek->game.player.sprite)))
        return;
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(tek->game.player.clock))
    > 70) {
        move_background(tek->game.background, tek->states, 10 *
        tek->game.player.speed);
        move_cam(tek->states, tek->editor.map_e, -10 * tek->game.player.speed,
        0);
        if (tek->game.player.rect.top == 15)
            tek->game.player.rect.top = 0;
        else
            tek->game.player.rect.top = 15;
        move_enemy(tek, 20);
        sfClock_restart(tek->game.player.clock);
    }
}

void move_left(tekmaker_t *tek)
{
    for (map_e_t *map = tek->editor.map_e; map; map = map->next) {
        if (sfSprite_getPosition(map->sprite).x < 0) {
            move_background(tek->game.background, tek->states, -10 *
            tek->game.player.speed);
            move_cam(tek->states, tek->editor.map_e, 10 *
            tek->game.player.speed, 0);
            return;
        }
    }
}

void move_player_left(tekmaker_t *tek)
{
    if (check_collision(tek, -10,
        sfSprite_getPosition(tek->game.player.sprite)))
        return;
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(tek->game.player.clock))
    > 70) {
        if (tek->game.player.rect.top == 45)
            tek->game.player.rect.top = 30;
        else
            tek->game.player.rect.top = 45;
        move_enemy(tek, 20);
        move_left(tek);
        sfClock_restart(tek->game.player.clock);
    }
}