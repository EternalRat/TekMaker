/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** gest_bonus
*/

#include <stdlib.h>
#include "tekmaker.h"

void fire_bonus(tekmaker_t *tek)
{
    if (tek->game.player.power_up.slow || tek->game.player.power_up.godmode
        || tek->game.player.power_up.fire)
        return;
    tek->game.player.rect.left = 32;
    tek->game.player.power_up.fire = true;
    sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
    tek->game.player.power_up.cooldown = sfClock_create();
    tek->game.player.power_up.anim = sfClock_create();
    tek->game.player.power_up.timer = sfClock_create();
}

void god_bonus(tekmaker_t *tek)
{
    if (tek->game.player.power_up.slow || tek->game.player.power_up.godmode
        || tek->game.player.power_up.fire)
        return;
    tek->game.player.rect.left = 16;
    sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
    tek->game.player.power_up.godmode = true;
    tek->game.player.power_up.timer = sfClock_create();
}

void speed_malus(tekmaker_t *tek)
{
    if (tek->game.player.power_up.slow || tek->game.player.power_up.godmode
        || tek->game.player.power_up.fire)
        return;
    tek->game.player.power_up.timer = sfClock_create();
    tek->game.player.speed /= 2;
    tek->game.settings.gravity *= 1.5;
    tek->game.player.power_up.slow = true;
}

void random_bonus(tekmaker_t *tek)
{
    int bonus = rand()%3;
    void (*func[])(tekmaker_t *) = {fire_bonus, god_bonus,
        speed_malus};

    if (tek->game.player.power_up.slow || tek->game.player.power_up.godmode
        || tek->game.player.power_up.fire)
        return;
    func[bonus](tek);
}

void check_for_bonus(tekmaker_t *tek, map_e_t *block)
{
    char *id = "89AB";
    void (*func[])(tekmaker_t *) = {random_bonus, fire_bonus, god_bonus,
        speed_malus};

    for (int i = 0; id[i]; i++) {
        if (id[i] == block->id && block->intrect.left != 50) {
            block->intrect.left = 50;
            sfSprite_setTextureRect(block->sprite, block->intrect);
            func[i](tek);
            break;
        }
    }
}