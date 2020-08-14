/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_player
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void init_player(player_t *player, game_settings_t settings)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 15, 15};

    player->texture = sfTexture_createFromFile("res/player.png", NULL);
    player->sprite = sfSprite_create();
    player->clock = sfClock_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, rect);
    sfSprite_scale(player->sprite, (sfVector2f){3.33, 3.33});
    player->rect = rect;
    player->jump = 1;
    player->is_jump = 0;
    player->speed = settings.speed;
    player->pos = pos;
    player->set_pos = -1;
    player->is_alive = 1;
    player->is_win = 0;
}