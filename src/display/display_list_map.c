/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** list_map
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void display_list(files_t file, windows_t windows)
{
    sfRenderWindow_drawSprite(windows.window, file.sprite, NULL);
    button_display(file.btn, windows.window);
    for (; file.files; file.files = file.files->next) {
        event_image(file.files, windows.window);
        sfRenderWindow_drawText(windows.window, file.files->text, NULL);
        sfRenderWindow_drawSprite(windows.window, file.files->sprite, NULL);
    }
}

void list_map(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    display_list(tek->files, tek->windows);
    sfRenderWindow_display(tek->windows.window);
}