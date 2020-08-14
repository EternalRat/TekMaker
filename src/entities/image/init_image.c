/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_image
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

static void set_sprite(image_t *image, sfVector2f pos, texture_t *path,
sfIntRect rect)
{
    float x = 0.00;
    float y = 0.00;

    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(path->path, NULL);
    x = (float)sfTexture_getSize(image->texture).x;
    y = (float)sfTexture_getSize(image->texture).y;
    image->intrect = (sfIntRect){rect.left, rect.top, x/2, y};
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    if (x == y)
        sfSprite_scale(image->sprite, (sfVector2f){50/x, 50/y});
    else if (x == 2*y) {
        sfSprite_scale(image->sprite, (sfVector2f){100/x, 50/y});
        sfSprite_setTextureRect(image->sprite, image->intrect);
    }
    else
        exit(84);
    sfSprite_setPosition(image->sprite, pos);
}

image_t *create_image(image_t **img, texture_t *path,
sfVector2f pos, sfIntRect rect)
{
    image_t *image = malloc(sizeof(image_t));
    image_t *tmp;

    if (!image)
        exit(84);
    image->id = path->id;
    set_sprite(image, pos, path, rect);
    image->next = NULL;
    if (!image->sprite)
        exit(84);
    if (*img == NULL)
        return (image);
    tmp = *img;
    for (; tmp->next; tmp = tmp->next);
    tmp->next = image;
    return (*img);
}

static void set_sprite_enemy(image_t *image, sfVector2f pos, char *path)
{
    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(path, NULL);
    image->intrect = (sfIntRect){0, 0, 50, 50};
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image->intrect);
    sfSprite_setPosition(image->sprite, pos);
}

image_t *create_image_enemy(image_t **img, char id, char *path,
sfVector2f pos)
{
    image_t *image = malloc(sizeof(image_t));
    image_t *tmp;

    if (!image)
        exit(84);
    image->id = id;
    set_sprite_enemy(image, pos, path);
    image->next = NULL;
    if (!image->sprite)
        exit(84);
    if (*img == NULL)
        return (image);
    tmp = *img;
    for (; tmp->next; tmp = tmp->next);
    tmp->next = image;
    return (*img);
}

void image(image_t **image, texture_t *path, sfVector2f pos, sfIntRect rect)
{
    char *enemy[] = {"res/goomba.png", "res/bill.png", NULL};
    char id[] = {"KL"};

    (*image) = NULL;
    for (texture_t *tmp = path; tmp; tmp = tmp->next) {
        (*image) = create_image(image, tmp, pos, rect);
        pos.x += 100;
    }
    for (int i = 0; enemy[i]; i++) {
        (*image) = create_image_enemy(image, id[i], enemy[i], pos);
        pos.x += 100;
    }
}