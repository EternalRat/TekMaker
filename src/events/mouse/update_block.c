/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** update_block.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int check_remove_first(map_e_t **map, map_e_t **previous, sfVector2f pos,
sfVector2i m_pos)
{
    if ((*map) == NULL)
        return (1);
    (*previous) = (*map);
    pos = sfSprite_getPosition((*previous)->sprite);
    if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
    m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
        (*map) = (*previous)->next;
        free((*previous));
        return (1);
    }
    return (0);
}

void destroy_current_block(map_e_t **tmp, map_e_t **previous)
{
    sfTexture_destroy((*tmp)->texture);
    sfSprite_destroy((*tmp)->sprite);
    (*previous)->next = (*tmp)->next;
    free((*tmp));
}

map_e_t *remove_block(tekmaker_t *tek, sfVector2i m_pos)
{
    sfVector2f pos;
    map_e_t *previous;

    if (check_pos(m_pos, tek))
        return (tek->editor.map_e);
    if (check_remove_first(&tek->editor.map_e, &previous, pos, m_pos))
        return (tek->editor.map_e);
    for (map_e_t *tmp = previous->next; tmp != NULL;
    previous = tmp, tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
            destroy_current_block(&tmp, &previous);
            map_set_char(tek->map, (m_pos.x - (m_pos.x % 50) +
            tek->editor.map_pos) / 50, (m_pos.y - (m_pos.y % 50) +
            tek->editor.map_pos_y) / 50, '0');
            return (tek->editor.map_e);
        }
    }
    return (tek->editor.map_e);
}

int check_selected_first(map_e_t **map, map_e_t **previous,
selected_block_t *block, sfVector2i m_pos)
{
    sfVector2f pos = {0, 0};

    if ((*map) == NULL) {
        return (2);
    }
    (*previous) = (*map);
    pos = sfSprite_getPosition((*previous)->sprite);
    if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
    m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
        create_selected_block(block, (*previous)->texture, (*previous)->id);
        sfTexture_destroy((*previous)->texture);
        sfSprite_destroy((*previous)->sprite);
        (*map) = (*previous)->next;
        free((*previous));
        return (1);
    }
    return (0);
}

map_e_t *selected_a_block_to_move(map_e_t *map, sfVector2i m_pos,
selected_block_t *block, tekmaker_t *tek)
{
    sfVector2f pos = {0, 0};
    map_e_t *previous;

    if (check_selected_first(&map, &previous, block, m_pos))
        return (map);
    for (map_e_t *tmp = previous->next; tmp != NULL;
    previous = tmp, tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->sprite);
        if (m_pos.x >= pos.x && m_pos.x <= pos.x + 50 &&
        m_pos.y >= pos.y && m_pos.y <= pos.y + 50) {
            create_selected_block(block, tmp->texture, tmp->id);
            destroy_current_block(&tmp, &previous);
            map_set_char(tek->map, (m_pos.x - (m_pos.x % 50) +
            tek->editor.map_pos) / 50, (m_pos.y - (m_pos.y % 50) +
            tek->editor.map_pos_y) / 50, '0');
            return (map);
        }
    }
    return (map);
}