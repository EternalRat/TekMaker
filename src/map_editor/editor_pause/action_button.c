/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** action_button
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void destroy_after_save(tekmaker_t *tek)
{
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    if (tek->selected_block.selected_block_sprite)
        sfSprite_destroy(tek->selected_block.selected_block_sprite);
    if (tek->selected_block.selected_block_texture)
        sfTexture_destroy(tek->selected_block.selected_block_texture);
    tek->selected_block.selected_block_sprite = NULL;
    tek->selected_block.selected_block_texture = NULL;
    tek->selected_block.selected_block_id = 0;
}

void edt_pause_save_map(tekmaker_t *tek)
{
    char *path = "maps/";
    char *final = malloc(sizeof(char) * (5 + strlen(tek->text_area.s) + 1));
    int i = 0;

    if (check_map(tek->map.map)) {
        free(final);
        return;
    }
    for (; path[i]; i++)
        final[i] = path[i];
    for (int j = 0; tek->text_area.s[j]; j++, i++)
        final[i] = tek->text_area.s[j];
    final[i] = '\0';
    map_save(final, tek->map);
    destroy_after_save(tek);
    tek->states = MENU;
    free(final);
}

void edt_pause_back(tekmaker_t *tek)
{
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    if (tek->selected_block.selected_block_sprite)
        sfSprite_destroy(tek->selected_block.selected_block_sprite);
    if (tek->selected_block.selected_block_texture)
        sfTexture_destroy(tek->selected_block.selected_block_texture);
    tek->selected_block.selected_block_sprite = NULL;
    tek->selected_block.selected_block_texture = NULL;
    tek->selected_block.selected_block_id = 0;
    tek->states = EDITOR_MENU;
}

void edt_pause_quit_menu(tekmaker_t *tek)
{
    destroy_map_block(tek->editor.map_e);
    tek->editor.map_e = NULL;
    if (tek->selected_block.selected_block_sprite)
        sfSprite_destroy(tek->selected_block.selected_block_sprite);
    if (tek->selected_block.selected_block_texture)
        sfTexture_destroy(tek->selected_block.selected_block_texture);
    tek->selected_block.selected_block_sprite = NULL;
    tek->selected_block.selected_block_texture = NULL;
    tek->selected_block.selected_block_id = 0;
    tek->states = MENU;
}