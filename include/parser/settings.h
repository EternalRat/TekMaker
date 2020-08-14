/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** settings
*/

#ifndef SETTINGS_H_
#define SETTINGS_H_

typedef struct settings_s settings_t;
struct settings_s
{
    int fps;
    int width;
    int height;
    int x_limit;
    int y_limit;
};

char **my_str_to_wordarray(char *str, char sep);
int parser_settings(settings_t *settings, char *path);

#endif /* !KEY_H_ */