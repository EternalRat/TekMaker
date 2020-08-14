/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** jump_player
*/

#include "tekmaker.h"

void jump_player(tekmaker_t *tek)
{
    if (tek->game.player.is_jump == 0) {
        tek->game.player.is_jump = 1;
        tek->game.player.jump = 45 / tek->game.settings.gravity;
    }
}

void check_and_unblock(tekmaker_t *tek)
{
    if (!check_if_a_block_is_hit_down(tek) && tek->game.player.is_jump == 0) {
        tek->game.player.pos.y += 3;
        sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
        if (check_if_a_block_is_hit_down(tek)) {
            tek->game.player.pos.y -= 3;
            sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
        }
    }
    if (check_if_a_block_is_hit_down(tek) && tek->game.player.is_jump == 0) {
        tek->game.player.pos.y -= 5;
        sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
    }
    if (check_if_a_block_is_hit_up(tek)) {
        tek->game.player.pos.y += 1;
        tek->game.player.jump = -0.1;
        sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
    }
}

void jump(tekmaker_t *tek)
{
    if (tek->game.player.is_jump == 1) {
        if (check_collision_jump_down(tek)) {
            tek->game.player.is_jump = 0;
            tek->game.player.pos.y += tek->game.player.jump;
            sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
            return;
        } else if (check_collision_jump_up(tek)) {
            tek->game.player.jump = -0.1;
        } else {
            tek->game.player.pos.y -= tek->game.player.jump;
            sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
            tek->game.player.jump -= 0.1;
        }
    }
    check_and_unblock(tek);
}