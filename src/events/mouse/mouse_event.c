/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** mouse_event
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void event_editor(tekmaker_t *tek)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(tek->windows.window);
    sfVector2f pos;

    if (sfMouse_isButtonPressed(sfMouseRight)) {
        tek->editor.map_e = remove_block(tek, m_pos);
        return;
    }
    for (image_t *img = tek->editor.image; img != NULL; img = img->next) {
        pos = sfSprite_getPosition(img->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
            create_selected_block(&tek->selected_block, img->texture, img->id);
            return;
        }
    }
    if (!place_block(tek, m_pos)) {
        tek->editor.map_e = selected_a_block_to_move(tek->editor.map_e,
        m_pos, &tek->selected_block, tek);
    }
}

void event_menu(menu_t menu, tekmaker_t *tek)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(tek->windows.window);
    sfVector2f pos;

    for (button_t *btn = menu.buttons; btn != NULL; btn = btn->next) {
        pos = sfSprite_getPosition(btn->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 400 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 80) {
            btn->callback(tek);
            return;
        }
    }
}

int check_and_create(list_files_t *img, tekmaker_t *tek)
{
    sfVector2f pos;
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(tek->windows.window);

    pos = sfSprite_getPosition(img->sprite);
    if (m_pos.x >= pos.x && m_pos.x <= pos.x + 200 &&
    m_pos.y >= pos.y && m_pos.y <= pos.y + 100) {
        map_load(img->path, tek->windows.settings, &tek->map);
        if (create_blocks(tek))
            return (1);
        choose_states(tek);
        return (1);
    }
    return (0);
}

void event_list_map(tekmaker_t *tek)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(tek->windows.window);
    sfVector2f pos;

    for (button_t *btn = tek->files.btn; btn != NULL; btn = btn->next) {
        pos = sfSprite_getPosition(btn->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 400 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 80) {
            btn->callback(tek);
            return;
        }
    }
    for (list_files_t *img = tek->files.files; img != NULL; img = img->next)
        if (check_and_create(img, tek))
            break;
}

void event_mouse(tekmaker_t *tek)
{
    menu_t menus[] = {tek->menu, tek->editor_menu, tek->editor_menu_pause,
        tek->game_pause};
    int menu[] = {MENU, EDITOR_MENU, EDITOR_PAUSE, GAME_PAUSE};

    for (int i = 0; i != 4; i++) {
        if (tek->states == menu[i]) {
            event_menu(menus[i], tek);
            break;
        }
    }
    if (tek->states == LIST_MAP || tek->states == EDIT_MAP)
        event_list_map(tek);
    if (tek->states == EDITOR)
        event_editor(tek);
}