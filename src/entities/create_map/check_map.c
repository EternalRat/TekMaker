/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** check_map
*/

#include "tekmaker.h"

int check_map(char *map)
{
    int start = 0;
    int end = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == '\n')
            continue;
        if (map[i] == 'G')
            start += 1;
        if (map[i] == 'H')
            end += 1;
    }
    if (start != 1 || end != 1)
        return (1);
    return (0);
}