/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** destroy
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_all(tekmaker_t *tek)
{
    destroy_button(tek->menu.buttons);
    destroy_button(tek->editor_menu.buttons);
    destroy_button(tek->files.btn);
    destroy_image(tek->editor.image);
}