/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** count_fireball
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_fireball(fireball_t *fireball)
{
    int count = 0;

    for (; fireball; fireball = fireball->next, count++);
    return (count);
}