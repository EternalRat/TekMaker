/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** menu_display
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

static void display_menu(menu_t men, windows_t windows)
{
    sfRenderWindow_drawSprite(windows.window, men.sprite, NULL);
    button_display(men.buttons, windows.window);
}

void menu_start(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_menu(tek->menu, tek->windows);
    sfRenderWindow_display(tek->windows.window);
}