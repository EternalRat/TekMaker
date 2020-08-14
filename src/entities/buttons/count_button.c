/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** count_button
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_button(button_t * btn)
{
    int count = 0;

    for (; btn; btn = btn->next, count++);
    return (count);
}