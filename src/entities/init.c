/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int init_menu(menu_t *menu, windows_t windows)
{
    void (*cb[])(tekmaker_t *) = {go_to_editor_menu, go_to_list, exit_game};
    int x = windows.settings.width;
    int y = windows.settings.height;
    sfVector2f pos = {(float)x / 2 - 200, (float)y / 2 - 150};
    char *name[] = {" map editor", "select a map", "\t  exit", NULL};

    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("res/Tekmaker_theme.png", NULL);
    menu->rect = (sfIntRect){0, 0, sfTexture_getSize(menu->texture).x,
        sfTexture_getSize(menu->texture).y};
    buttons(&menu->buttons, cb, pos, name);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_scale(menu->sprite,
    (sfVector2f){(float)x/(float)menu->rect.width,
        (float)y/(float)menu->rect.height});
    return (0);
}

int init_editor_menu(menu_t *menu, windows_t windows)
{
    void (*callback[])(tekmaker_t *) = {go_to_editor, go_to_edit_map, go_back};
    int x = windows.settings.width;
    int y = windows.settings.height;
    sfVector2f pos = {(float)x / 2 - 200, (float)y / 2 - 150};
    char *name[] = {"create a map", " edit a map", "\t  back", NULL};

    buttons(&menu->buttons, callback, pos, name);
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("res/Tekmaker_theme.png", NULL);
    menu->rect = (sfIntRect){0, 0, sfTexture_getSize(menu->texture).x,
        sfTexture_getSize(menu->texture).y};
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_scale(menu->sprite,
    (sfVector2f){(float)x/(float)menu->rect.width,
        (float)y/(float)menu->rect.height});
    return (0);
}

void init_editor(editor_t *editor, settings_t setting)
{
    sfIntRect rect = {0, 0, 50, 50};
    sfVector2f pos = {50, setting.height - 100};

    editor->background = NULL;
    create_background(&editor->background, setting);
    editor->map_e = NULL;
    image(&editor->image, editor->path, pos, rect);
    editor->map_pos = 0;
    editor->map_pos_y = 0;
    editor->select_block_pos = 0;
}

void init_settings(settings_t *settings, key_config_t *key,
game_settings_t *game)
{
    key->jump = sfKeySpace;
    key->down = sfKeyDown;
    key->left = sfKeyLeft;
    key->right = sfKeyRight;
    key->fire = sfKeyE;
    key->editor_right = sfKeyR;
    key->editor_left = sfKeyL;
    settings->fps = 60;
    settings->width = 1280;
    settings->height = 720;
    settings->x_limit = 50;
    settings->y_limit = 11;
    game->gravity = 9.81;
    game->speed = 1.00;
    game->cooldown = 1.00;
}

void init_tek(tekmaker_t *tek, char *file)
{
    sfVideoMode mode;

    tek->files.files = NULL;
    tek->files.btn = NULL;
    tek->selected_block.selected_block_sprite = NULL;
    tek->selected_block.selected_block_texture = NULL;
    init_settings(&tek->windows.settings, &tek->key, &tek->game.settings);
    parser(tek, file);
    mode = (sfVideoMode){tek->windows.settings.width,
        tek->windows.settings.height, 32};
    tek->windows.window = create_windows(mode);
    if (tek->windows.window == NULL)
        exit(84);
    init_menu(&tek->menu, tek->windows);
    init_editor_menu(&tek->editor_menu, tek->windows);
    init_editor(&tek->editor, tek->windows.settings);
    init_game(tek);
    tek->states = MENU;
    tek->old_states = MENU;
}