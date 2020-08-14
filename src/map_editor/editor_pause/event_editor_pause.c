/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** menu
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void fill_text(tekmaker_t *tek)
{
    for (int i = 0; i != 26; i++) {
        if (tek->text_area.keycode[i] == tek->windows.event.key.code) {
            int j = strlen(tek->text_area.s);
            tek->text_area.s = realloc(tek->text_area.s, j + 2);
            tek->text_area.s[j] = tek->text_area.test[i];
            tek->text_area.s[j + 1] = '\0';
            break;
        }
    }
}

void event_editor_pause(tekmaker_t *tek)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack)) {
        if (strlen(tek->text_area.s) > 0)
            tek->text_area.s[strlen(tek->text_area.s) - 1] = '\0';
    } else if (strlen(sfText_getString(tek->text_area.text)) >= 6)
        return;
    else
        fill_text(tek);
    sfText_setString(tek->text_area.text, tek->text_area.s);
}