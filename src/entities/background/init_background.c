/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_background
*/

#include "tekmaker.h"
#include <stdlib.h>

void display_background(background_t *background, sfRenderWindow *window)
{
    for (background_t *tmp = background; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

background_t *init_background(background_t **background, char *path, int speed,
settings_t settings)
{
    background_t *back = malloc(sizeof(background_t));
    background_t *tmp;

    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile(path, NULL);
    back->speed = speed;
    back->rect = (sfIntRect){0, 0, sfTexture_getSize(back->texture).x,
        sfTexture_getSize(back->texture).y};
    sfSprite_scale(back->sprite,
    (sfVector2f){(float)settings.width / (float)1280,
        (float)settings.height / (float)back->rect.height});
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    sfSprite_setTextureRect(back->sprite, back->rect);
    sfSprite_setPosition(back->sprite, (sfVector2f){0, 0});
    back->next = NULL;
    if ((*background) == NULL)
        return (back);
    for (tmp = (*background); tmp->next; tmp = tmp->next);
    tmp->next = back;
    return ((*background));
}

void create_background(background_t **background, settings_t setting)
{
    char *path[] = {"res/bg1.png", "res/bg2.png", NULL};
    int speed[] = {1, 2};

    for (int i = 0; path[i]; i++)
        (*background) = init_background(background, path[i], speed[i], setting);
}