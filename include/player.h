/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** player.h
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct fireball_s fireball_t;
struct fireball_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int sens;
    fireball_t *next;
};


typedef struct power_up_s power_up_t;
struct power_up_s
{
    fireball_t *fireball;
    sfClock *anim;
    sfClock *cooldown;
    sfClock *timer;
    bool godmode;
    bool slow;
    bool fire;
};

typedef struct player_s player_t;
struct player_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    power_up_t power_up;
    float jump;
    int is_jump;
    float speed;
    int set_pos;
    int is_alive;
    int is_win;
};

#endif