/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** game.h
*/

#include <SFML/Graphics.h>

#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"
#include "editor.h"
#include "enemy.h"
#include "parser/game_settings.h"

typedef struct background_s background_t;
struct background_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int speed;
    background_t *next;
};

typedef struct game_s game_t;
struct game_s
{
    game_settings_t settings;
    background_t *background;
    enemy_t *enemy;
    player_t player;
    int gravity;
};

void display_background(background_t *background, sfRenderWindow *window);
void create_background(background_t **background, settings_t setting);

#endif