/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** bonus
*/

#include "tekmaker.h"
#include <unistd.h>

void godmode(tekmaker_t *tek)
{
    sfTime time = sfClock_getElapsedTime(tek->game.player.power_up.timer);

    if (sfTime_asMilliseconds(time) > 10000) {
        tek->game.player.power_up.godmode = false;
        tek->game.player.rect.left = 0;
        sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
        sfClock_destroy(tek->game.player.power_up.timer);
        tek->game.player.power_up.timer = NULL;
    }
}

void fire(tekmaker_t *tek)
{
    sfTime time = sfClock_getElapsedTime(tek->game.player.power_up.timer);

    if (sfTime_asMilliseconds(time) > 10000) {
        tek->game.player.rect.left = 0;
        sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
        tek->game.player.power_up.fire = false;
        sfClock_destroy(tek->game.player.power_up.timer);
        sfClock_destroy(tek->game.player.power_up.anim);
        sfClock_destroy(tek->game.player.power_up.cooldown);
        tek->game.player.power_up.cooldown = NULL;
        tek->game.player.power_up.timer = NULL;
        tek->game.player.power_up.anim = NULL;
        destroy_all_fireball(tek->game.player.power_up.fireball);
        tek->game.player.power_up.fireball = NULL;
    }
}

void slow(tekmaker_t *tek)
{
    sfTime time = sfClock_getElapsedTime(tek->game.player.power_up.timer);

    if (sfTime_asMilliseconds(time) > 10000) {
        tek->game.player.speed *= 2;
        tek->game.player.power_up.slow = false;
        tek->game.settings.gravity /= 1.5;
        sfClock_destroy(tek->game.player.power_up.timer);
        tek->game.player.power_up.timer = NULL;
    }
}

void check_bonus(tekmaker_t *tek)
{
    if (tek->game.player.power_up.godmode)
        godmode(tek);
    if (tek->game.player.power_up.fire)
        fire(tek);
    if (tek->game.player.power_up.slow)
        slow(tek);
}