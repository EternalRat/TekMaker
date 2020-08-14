/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** list_map
*/

#include <SFML/Graphics.h>

#ifndef LIST_MAP_H_
#define LIST_MAP_H_

typedef struct list_files_s list_files_t;
struct list_files_s
{
    char *path;
    char *name;
    sfText *text;
    sfSprite *sprite;
    sfTexture *texture;
    list_files_t *next;
};

typedef struct files_s files_t;
struct files_s
{
    list_files_t *files;
    button_t *btn;
    sfSprite *sprite;
    sfTexture *texture;
};

void free_list(files_t *files);

#endif /* !LIST_MAP_H_ */
