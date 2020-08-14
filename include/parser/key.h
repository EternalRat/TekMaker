/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** key
*/

#ifndef KEY_H_
#define KEY_H_

typedef struct key_config_s key_config_t;
struct key_config_s
{
    int jump;
    int down;
    int left;
    int right;
    int fire;
    int editor_left;
    int editor_right;
};

typedef struct keys_s keys_t;
struct keys_s
{
    int key;
    char *config;
};

char **my_str_to_wordarray(char *str, char sep);
int parser_key(key_config_t *config, char *path);

#endif /* !KEY_H_ */