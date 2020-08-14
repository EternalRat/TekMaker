/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_game.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int init_game_pause_menu(menu_t *menu, windows_t windows)
{
    void (*callback[])(tekmaker_t *) = {go_back, edt_pause_quit_menu};
    int x = windows.settings.width;
    int y = windows.settings.height;
    sfVector2f pos = {(float)x / 2 - 200, (float)y / 2 - 100};
    char *name[] = {"\t Back", "\t Menu", NULL};

    menu->buttons = NULL;
    buttons(&menu->buttons, callback, pos, name);
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("res/Tekmaker_theme.png", NULL);
    menu->rect = (sfIntRect){0, 0, sfTexture_getSize(menu->texture).x,
        sfTexture_getSize(menu->texture).y};
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_scale(menu->sprite,
    (sfVector2f){(float)x/(float)menu->rect.width,
        (float)y/(float)menu->rect.height});
    return (0);
}

void init_game(tekmaker_t *tek)
{
    tek->game.gravity = tek->game.settings.gravity;
    tek->game.background = NULL;
    tek->game.player.power_up.cooldown = NULL;
    tek->game.player.power_up.fire = false;
    tek->game.player.power_up.godmode = false;
    tek->game.player.power_up.slow = false;
    tek->game.player.power_up.fireball = NULL;
    tek->game.player.power_up.anim = NULL;
    tek->game.player.power_up.timer = NULL;
    init_player(&tek->game.player, tek->game.settings);
    create_background(&tek->game.background, tek->windows.settings);
    init_game_pause_menu(&tek->game_pause, tek->windows);
}