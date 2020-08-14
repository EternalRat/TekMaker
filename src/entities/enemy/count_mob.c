/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** count_mob
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_enemy(enemy_t *enemy)
{
    int count = 0;

    for (; enemy; enemy = enemy->next, count++);
    return (count);
}