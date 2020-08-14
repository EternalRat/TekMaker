/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** pause_menu
*/

#include "tekmaker.h"

static void display_menu(menu_t men, windows_t windows)
{
    sfRenderWindow_drawSprite(windows.window, men.sprite, NULL);
    button_display(men.buttons, windows.window);
}

void evt_pause_menu(tekmaker_t *tek)
{
    tek->old_states = GAME;
    tek->states = GAME_PAUSE;
}

void pause_menu(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_menu(tek->game_pause, tek->windows);
    sfRenderWindow_display(tek->windows.window);
}