/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** game_settings
*/

#ifndef GAME_SETTINGS_H_
#define GAME_SETTINGS_H_

typedef struct game_settings_s game_settings_t;
struct game_settings_s
{
    float gravity;
    float speed;
    float cooldown;
};

int parser_game(game_settings_t *settings, char *path);
char **my_str_to_wordarray(char *str, char sep);

#endif /* !GAME_SETTINGS_H_ */