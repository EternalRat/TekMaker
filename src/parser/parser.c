/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** parser
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_array(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}

void parser(tekmaker_t *tek, char *files)
{
    if (parser_game(&tek->game.settings, "config/game")) {
        write(1, "Invalid(s) game setting(s).\n", 28);
        exit(84);
    }
    parser_texture(files, tek);
    if (parser_settings(&tek->windows.settings, "config/settings")) {
        write(1, "Invalid(s) setting(s).\n", 23);
        exit(84);
    }
    if (parser_key(&tek->key, "config/key")) {
        write(1, "Invalid(s) key(s).\n", 19);
        exit(84);
    }
}