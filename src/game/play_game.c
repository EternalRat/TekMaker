/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** play_game.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void manage_collision(tekmaker_t *tek)
{
    if (check_collision_with_ennemy(tek, tek->game.player.pos) &&
        tek->game.player.power_up.godmode == false)
        tek->game.player.is_alive = 0;
    if (check_collision_with_hurting_block(tek, 10 * tek->game.player.speed
        , tek->game.player.pos) && tek->game.player.power_up.godmode == false)
        tek->game.player.is_alive = 0;
    if (check_collision_with_hurting_blocks(tek,
        tek->game.player.pos) && tek->game.player.power_up.godmode == false)
        tek->game.player.is_alive = 0;
    if (check_collision_with_end(tek, 10 * tek->game.player.speed,
        tek->game.player.pos))
        tek->game.player.is_win = 1;
    if (tek->game.player.power_up.slow == false)
        tek->game.player.speed = tek->game.settings.speed;
    if (check_if_good_block_is_hit_down(tek, 'E'))
        tek->game.player.speed = tek->game.settings.speed / 2;
    if (check_if_good_block_is_hit_down(tek, 'F'))
        tek->game.player.speed = tek->game.settings.speed * 2;
    if (tek->game.player.pos.y >= tek->windows.settings.height)
        tek->game.player.is_alive = 0;
}

void play_game(tekmaker_t *tek)
{
    if (tek->game.player.jump != 0)
        jump(tek);
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_background(tek->game.background, tek->windows.window);
    map_display(tek->editor.map_e, tek->windows, tek->states);
    display_enemy(tek, 10);
    manage_collision(tek);
    check_bonus(tek);
    display_fireball(&tek->game.player.power_up, tek->windows, tek);
    sfRenderWindow_drawSprite(tek->windows.window, tek->game.player.sprite,
    NULL);
    if (tek->game.player.is_alive == 0)
        menu_mort(tek);
    if (tek->game.player.is_win == 1)
        menu_win(tek);
    sfRenderWindow_display(tek->windows.window);
}