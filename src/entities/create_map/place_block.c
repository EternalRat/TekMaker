/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** place_block
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int check_if_its_a_block(tekmaker_t *tek, sfVector2i m_pos)
{
    sfVector2f pos;

    for (map_e_t *map = tek->editor.map_e; map; map = map->next) {
        pos = sfSprite_getPosition(map->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
            return (1);
        }
    }
    for (map_e_t *map = tek->editor.map_e; map; map = map->next) {
        if (map->id == 'G' && tek->selected_block.selected_block_id == 'G')
            return (1);
        if (map->id == 'H' && tek->selected_block.selected_block_id == 'H')
            return (1);
    }
    return (0);
}

int check_pos(sfVector2i m_pos, tekmaker_t *tek)
{
    if (m_pos.y >= tek->windows.settings.height - 125)
        return (1);
    if ((m_pos.y <= tek->windows.settings.height -
        tek->windows.settings.y_limit * 50 - 125) ||
        (m_pos.x + tek->editor.map_pos >=
        tek->windows.settings.x_limit * 50))
        return (1);
    return (0);
}

int place_block(tekmaker_t *tek, sfVector2i m_pos)
{
    if (tek->selected_block.selected_block_sprite &&
    tek->selected_block.selected_block_texture) {
        if (check_pos(m_pos, tek))
            return (1);
        if (check_if_its_a_block(tek, m_pos))
            return (0);
        tek->editor.map_e = create_map_block(&tek->editor.map_e, m_pos,
        tek->selected_block.selected_block_texture,
        tek->selected_block.selected_block_id);
        map_set_char(tek->map, (m_pos.x - (m_pos.x % 50) + tek->editor.map_pos)
        / 50, (m_pos.y - (m_pos.y % 50) + tek->editor.map_pos_y) / 50,
        tek->selected_block.selected_block_id);
    }
    return (1);
}