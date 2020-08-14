/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** count_image
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_block(map_e_t *map)
{
    int count = 0;

    for (; map; map = map->next, count++);
    return (count);
}