/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** map.h
*/

#ifndef _MAP_H_
#define _MAP_H_

#define AIR (0)

typedef struct map_s map_t;

#include "parser/settings.h"

struct map_s
{
    int width;
    int height;
    char *map;
};

void map_load(char *filename, settings_t settings, map_t *map);
void map_realloc_collumn(map_t *map);
void map_set_char(map_t map, int posx, int posy, char block);
void map_save(char *filename, map_t map);
void map_create(settings_t set, map_t *map);

#endif