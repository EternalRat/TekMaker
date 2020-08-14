/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** menu.h
*/

#include <SFML/Graphics.h>
#include "button.h"

#ifndef _MENU_H_
#define _MENU_H_

typedef struct menu_s menu_t;
struct menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    button_t *buttons;
};

#endif