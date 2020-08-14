/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** init_fireball
*/

#include "tekmaker.h"
#include <stdlib.h>

int is_hitting_an_enemy(fireball_t *tmp, enemy_t *enemy)
{
    sfVector2f pos;

    for (enemy_t *tmp_enemy = enemy; tmp_enemy; tmp_enemy = tmp_enemy->next) {
        pos = sfSprite_getPosition(tmp_enemy->sprite);
        if ((((pos.x <= (tmp->pos.x)) && (pos.x + 50 >=
        (tmp->pos.x)) && (pos.y <= tmp->pos.y + 10) && (pos.y + 50 >=
        tmp->pos.y + 10)) || ((pos.x <= (tmp->pos.x + 25)) && (pos.x + 50
        >= (tmp->pos.x + 25)) && (pos.y <= tmp->pos.y + 10) &&
        (pos.y + 50 >= tmp->pos.y + 10))) && tmp_enemy->end == 450) {
            tmp_enemy->pos = (sfVector2f){-5000, 10000};
            sfSprite_setPosition(tmp_enemy->sprite, tmp_enemy->pos);
            return (1);
        }
    }
    return (0);
}

int is_hitting_a_wall(fireball_t *tmp, map_e_t *map)
{
    sfVector2f pos;

    for (map_e_t *tmp_map = map; tmp_map; tmp_map = tmp_map->next) {
        pos = sfSprite_getPosition(tmp_map->sprite);
        if ((((pos.x < (tmp->pos.x)) && (pos.x + 50 >
        (tmp->pos.x)) && (pos.y <= tmp->pos.y + 10) && (pos.y + 45 >=
        tmp->pos.y + 10)) || ((pos.x < (tmp->pos.x + 25)) && (pos.x + 50
        > (tmp->pos.x + 25)) && (pos.y <= tmp->pos.y + 10) &&
        (pos.y + 45 >= tmp->pos.y + 10)))) {
            return (1);
        }
    }
    return (0);
}

void display_fireball(power_up_t *power, windows_t windows, tekmaker_t *tek)
{
    sfTime time;

    if (power->fire == false)
        return;
    time = sfClock_getElapsedTime(power->anim);
    if (sfTime_asMilliseconds(time) < 10)
        return;
    for (fireball_t *tmp = power->fireball; tmp; tmp = tmp->next) {
        tmp->pos.x += 10 * tmp->sens;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        if (is_hitting_an_enemy(tmp, tek->game.enemy) ||
        is_hitting_a_wall(tmp, tek->editor.map_e)) {
            tmp->pos = (sfVector2f){-5000, 10000};
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            continue;
        }
        sfRenderWindow_drawSprite(windows.window, tmp->sprite, NULL);
    }
    sfClock_restart(power->anim);
}

fireball_t *init_fireball(fireball_t **fireball, sfVector2f pos, int sens)
{
    fireball_t *tmp;
    fireball_t *fire = malloc(sizeof(fireball_t));

    fire->sprite = sfSprite_create();
    fire->texture = sfTexture_createFromFile("res/fireball.png", NULL);
    fire->pos = (sfVector2f){pos.x + 30, pos.y + 25};
    fire->sens = sens;
    fire->next = NULL;
    sfSprite_setPosition(fire->sprite, fire->pos);
    sfSprite_setTexture(fire->sprite, fire->texture, sfTrue);
    sfSprite_setScale(fire->sprite, (sfVector2f){0.25, 0.25});
    if (!(*fireball))
        return (fire);
    for (tmp = *fireball; tmp->next; tmp = tmp->next);
    tmp->next = fire;
    return (*fireball);
}

void shooting_fire(tekmaker_t *tek)
{
    sfTime time;
    int sens = 0;

    if (tek->game.player.power_up.fire == false)
        return;
    time = sfClock_getElapsedTime(tek->game.player.power_up.cooldown);
    if (sfTime_asMilliseconds(time) < tek->game.settings.cooldown * 1000)
        return;
    sens = tek->game.player.rect.top >= 30 ? -1 : 1;
    tek->game.player.power_up.fireball =
    init_fireball(&tek->game.player.power_up.fireball,
    sfSprite_getPosition(tek->game.player.sprite), sens);
    sfClock_restart(tek->game.player.power_up.cooldown);
}