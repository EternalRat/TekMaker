/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** main
*/

#include "map.h"
#include "parser/settings.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void map_set_char(map_t map, int posx, int posy, char block)
{
    int x = 0;
    int y = 0;

    for (int i = 0; map.map[i] != '\0'; i++) {
        if (x == posx && posy == y + 1)
            map.map[i] = block;
        if (map.map[i] == '\n') {
            y++;
            x = 0;
        } else
            x++;
    }
}

void map_realloc_collumn(map_t *map)
{
    map->map = realloc(map->map, strlen(map->map) + map->height + 1);
    map->width += 1;
    if (map->map == NULL)
        exit(84);
}