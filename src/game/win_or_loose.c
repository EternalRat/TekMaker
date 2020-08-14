/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** win_or_loose
*/

#include "tekmaker.h"

void destroy_clock(sfClock **clock)
{
    sfClock_destroy((*clock));
    (*clock) = NULL;
}

void destroy_object(tekmaker_t *tek)
{
    destroy_all_mob(tek->game.enemy);
    tek->game.enemy = NULL;
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    if (tek->game.player.power_up.anim)
        destroy_clock(&tek->game.player.power_up.anim);
    if (tek->game.player.power_up.cooldown)
        destroy_clock(&tek->game.player.power_up.cooldown);
    if (tek->game.player.power_up.timer)
        destroy_clock(&tek->game.player.power_up.timer);
    if (tek->game.player.power_up.slow) {
        tek->game.player.speed *= 2;
        tek->game.settings.gravity /= 1.5;
    }
    tek->game.player.power_up.slow = false;
    tek->game.player.power_up.fire = false;
    tek->game.player.power_up.godmode = false;
    tek->game.player.power_up.fireball = NULL;
    tek->game.player.rect.left = 0;
    sfSprite_setTextureRect(tek->game.player.sprite, tek->game.player.rect);
}

void menu_mort(tekmaker_t *tek)
{
    sfClock *clock = sfClock_create();
    sfFont *font = sfFont_createFromFile("res/textures/SuperMario256.ttf");
    sfText *text = sfText_create();

    sfText_setString(text, "Game over.");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f){tek->windows.settings.width / 2 -
        150, tek->windows.settings.height / 2 - 50});
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 3000) {
        sfRenderWindow_clear(tek->windows.window, sfBlack);
        sfRenderWindow_drawText(tek->windows.window, text, NULL);
        sfRenderWindow_display(tek->windows.window);
    }
    tek->states = MENU;
    tek->game.player.is_alive = 1;
    destroy_object(tek);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clock);
}

void menu_win(tekmaker_t *tek)
{
    sfClock *clock = sfClock_create();
    sfFont *font = sfFont_createFromFile("res/textures/SuperMario256.ttf");
    sfText *text = sfText_create();

    sfText_setString(text, "You won!");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f){tek->windows.settings.width / 2 -
        125, tek->windows.settings.height / 2 - 50});
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 3000) {
        sfRenderWindow_clear(tek->windows.window, sfBlack);
        sfRenderWindow_drawText(tek->windows.window, text, NULL);
        sfRenderWindow_display(tek->windows.window);
    }
    tek->states = MENU;
    tek->game.player.is_win = 0;
    destroy_object(tek);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfClock_destroy(clock);
}