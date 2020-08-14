/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** exit_game
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void exit_game(tekmaker_t *tek)
{
    sfRenderWindow_close(tek->windows.window);
}