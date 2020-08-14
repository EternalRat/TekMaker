/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** event_handler
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void event_handler(tekmaker_t *tek)
{
    switch (tek->windows.event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(tek->windows.window);
        break;
    case sfEvtMouseButtonPressed:
        event_mouse(tek);
        break;
    case sfEvtKeyPressed:
        event_key(tek);
        break;
    default:
        break;
    }
}