/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** editor
*/

#include <SFML/Graphics.h>

#ifndef EDITOR_H_
#define EDITOR_H_
#include "game.h"

typedef struct image_s image_t;
struct image_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect intrect;
    char id;
    image_t *next;
};

typedef struct map_e_s map_e_t;
struct map_e_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect intrect;
    char id;
    map_e_t *next;
};

typedef struct texture_s texture_t;
struct texture_s {
    char *path;
    char id;
    texture_t *next;
};

typedef struct editor_s editor_t;
struct editor_s
{
    background_t *background;
    texture_t *path;
    image_t *image;
    map_e_t *map_e;
    int map_pos;
    int map_pos_y;
    int select_block_pos;
};

void image_display(image_t *images, sfRenderWindow *windows);
map_e_t *create_map_block(map_e_t **map, sfVector2i pos,
sfTexture *texture, char id);
void image(image_t **image, texture_t *path, sfVector2f pos, sfIntRect rect);
int count_image(image_t *img);
void destroy_image(image_t *img);

#endif /* !EDITOR_H_ */