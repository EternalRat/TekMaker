/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** menu
*/

#include "tekmaker.h"
#include <stdlib.h>

void create_text(tekmaker_t *tek)
{
    int x = tek->windows.settings.width;
    int y = tek->windows.settings.height;

    tek->text_area.font = sfFont_createFromFile(FONT);
    tek->text_area.s = malloc(sizeof(char) * 2);
    tek->text_area.text = sfText_create();
    sfText_setCharacterSize(tek->text_area.text, 30);
    sfText_setFont(tek->text_area.text, tek->text_area.font);
    sfText_setPosition(tek->text_area.text, (sfVector2f){(float)x / 2 - 200,
        (float)y / 2 - 250});
}

void editor_pause(tekmaker_t *tek)
{
    tek->states = EDITOR_PAUSE;
    void (*cb[])(tekmaker_t *) = {edt_pause_save_map, edt_pause_back,
        edt_pause_quit_menu};
    int x = tek->windows.settings.width;
    int y = tek->windows.settings.height;
    sfVector2f pos = {(float)x / 2 - 200, (float)y / 2 - 150};
    char *name[] = {"Save", "Back", "Menu", NULL};
    int nbr[] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
        sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP,
        sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY,
        sfKeyZ};

    buttons(&tek->editor_menu_pause.buttons, cb, pos, name);
    create_text(tek);
    tek->text_area.test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i != 27; i++)
        tek->text_area.keycode[i] = nbr[i];
    tek->text_area.s[0] = '\0';
    return;
}

void editor_pause_loop(tekmaker_t *tek)
{
    sfRenderWindow_clear(tek->windows.window, sfBlack);
    sfRenderWindow_drawText(tek->windows.window, tek->text_area.text, NULL);
    button_display(tek->editor_menu_pause.buttons, tek->windows.window);
    sfRenderWindow_display(tek->windows.window);
}