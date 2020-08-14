/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** choose_states.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void choose_states(tekmaker_t *tek)
{
    if (tek->states == LIST_MAP) {
        tek->old_states = LIST_MAP;
        tek->states = GAME;
    }
    if (tek->states == EDIT_MAP) {
        tek->old_states = EDIT_MAP;
        tek->states = EDITOR;
    }
}