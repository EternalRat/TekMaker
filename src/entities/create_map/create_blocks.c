/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** create_block.c
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

char *choose_filename(tekmaker_t *tek, char c)
{
    char *path[] = {"res/goomba.png", "res/bill.png", NULL};
    char *id = "KL";

    for (texture_t *tmp = tek->editor.path; tmp; tmp = tmp->next)
        if (tmp->id == c)
            return (tmp->path);
    for (int i = 0; path[i]; i++)
        if (id[i] == c)
            return (path[i]);
    return (NULL);
}

void choice_enemy_or_block(tekmaker_t *tek, sfVector2i pos, char c,
sfTexture *texture)
{
    int stat[2][3] = {{1, 1, 250}, {2, 999, 0}};

    if (tek->states == LIST_MAP) {
        if (c != 'K' && c != 'L') {
            tek->editor.map_e = create_map_block(&tek->editor.map_e,
            pos, texture, c);
            return;
        }
        if (c == 'K') {
            tek->game.enemy = init_enemy(&tek->game.enemy, texture, pos,
            stat[0]);
        } else if (c == 'L') {
            tek->game.enemy = init_enemy(&tek->game.enemy, texture, pos,
            stat[1]);
        }
    } else
        tek->editor.map_e = create_map_block(&tek->editor.map_e,
        pos, texture, c);
}

int add_block_or_nothing(tekmaker_t *tek, sfVector2i pos, char c)
{
    sfTexture *texture;
    char *path = NULL;

    if (c != '0') {
        if (c == 'G' && tek->states == LIST_MAP) {
            tek->game.player.pos =
            (sfVector2f){pos.x - (pos.x % 50), pos.y - (pos.y % 50)};
            sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
            return (0);
        }
        path = choose_filename(tek, c);
        if (path == NULL)
            return (1);
        texture = sfTexture_createFromFile(path, NULL);
        choice_enemy_or_block(tek, pos, c, texture);
        sfTexture_destroy(texture);
    }
    return (0);
}

void check_pos_and_modify(tekmaker_t *tek)
{
    sfVector2f b_pos;

    if (tek->states != LIST_MAP)
        return;
    for (map_e_t *map = tek->editor.map_e; map; map = map->next) {
        b_pos = sfSprite_getPosition(map->sprite);
        sfSprite_setPosition(map->sprite, (sfVector2f){b_pos.x -
            tek->game.player.pos.x + 50, b_pos.y});
    }
    tek->game.player.pos.x = 50;
    sfSprite_setPosition(tek->game.player.sprite, tek->game.player.pos);
}

int create_blocks(tekmaker_t *tek)
{
    sfVector2i pos = {0,
        (tek->windows.settings.height - tek->map.height * 50 - 100)};

    if (check_map(tek->map.map))
        return (1);
    tek->game.enemy = NULL;
    for (int i = 0; tek->map.map[i]; i++, pos.x += 50) {
        if (tek->map.map[i] == '\n') {
            pos.x = -50;
            pos.y += 50;
            continue;
        }
        if (add_block_or_nothing(tek, pos, tek->map.map[i]))
            exit(84);
    }
    check_pos_and_modify(tek);
    return (0);
}