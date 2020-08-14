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

void map_load(char *filename, settings_t settings, map_t *map)
{
    struct stat fstat;
    int fd = open(filename, O_RDONLY);

    if (stat(filename, &fstat) == -1)
        exit(84);
    map->map = malloc(sizeof(char) * (fstat.st_size + 1));
    read(fd, map->map, fstat.st_size);
    map->map[fstat.st_size] = '\0';
    map->width = settings.x_limit;
    map->height = settings.y_limit;
    close(fd);
}

void map_create(settings_t set, map_t *map)
{
    map->map = malloc(sizeof(char) * ((set.x_limit + 1) * set.y_limit + 1));
    map->width = set.x_limit;
    map->height = set.y_limit;
    for (int i = 1; i != (set.x_limit + 1) * set.y_limit; i++) {
        if (i % map->width == 0 && i != 0)
            map->map[i - 1] = '\n';
        else
            map->map[i - 1] = '0';
    }
    map->map[set.x_limit * set.y_limit] = '\0';

}

void map_save(char *filename, map_t map)
{
    int fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);

    if (fd == -1)
        exit(84);
    write(fd, map.map, strlen(map.map));
    close(fd);
}