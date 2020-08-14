/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** enemy
*/

#include <SFML/Graphics.h>

#ifndef ENEMY_H_
#define ENEMY_H_

typedef struct enemy_s enemy_t;
struct enemy_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    int speed;
    int hp;
    int end;
    int start;
    enemy_t *next;
};

enemy_t *init_enemy(enemy_t **enemy, sfTexture *texture, sfVector2i pos,
int *stat);


#endif /* !ENEMY_H_ */