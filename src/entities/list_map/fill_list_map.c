/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** fill_list_map
*/

#include "tekmaker.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *fill_name(char *file)
{
    char *path = malloc(sizeof(char) * (strlen(file) + strlen("maps/") + 1));
    char *maps = "maps/";
    int j = 0;

    for (int i = 0; maps[i]; i++, j++)
        path[j] = maps[i];
    for (int i = 0; file[i]; i++, j++)
        path[j] = file[i];
    path[j] = '\0';
    return (path);
}

static void set_sprite(list_files_t *file, sfVector2f pos)
{
    float x = 0.1893939393939394;
    float y = 0.15151515151515152;

    file->sprite = sfSprite_create();
    file->texture = sfTexture_createFromFile("res/maplist.png", NULL);
    sfSprite_setTexture(file->sprite, file->texture, sfTrue);
    sfSprite_setScale(file->sprite, (sfVector2f){x, y});
    sfSprite_setPosition(file->sprite, (sfVector2f){pos.x, pos.y});
}

list_files_t *fill_struct_files(list_files_t *files, char *name,
sfVector2f textpos)
{
    sfFont *font = sfFont_createFromFile("./res/textures/SuperMario256.ttf");
    list_files_t *file = malloc(sizeof(list_files_t));
    list_files_t *tmp;

    file->path = fill_name(name);
    file->name = strdup(name);
    file->text = sfText_create();
    set_sprite(file, textpos);
    sfText_setString(file->text, file->name);
    sfText_setFont(file->text, font);
    sfText_setCharacterSize(file->text, 30);
    sfText_setPosition(file->text, (sfVector2f){textpos.x, textpos.y + 100.0});
    file->next = NULL;
    if (files == NULL)
        return (file);
    tmp = files;
    for (; tmp->next; tmp = tmp->next);
    tmp->next = file;
    return (files);
}

void complete_struct_and_change_menu(tekmaker_t *tek, DIR **dir)
{
    float x = 3.018867924528302;
    float y = 8.0;
    void (*func[])(tekmaker_t *) = {go_back};
    char *name[] = {"\t back", NULL};
    sfVector2f pos = {tek->windows.settings.width - 430,
        tek->windows.settings.height - 100};

    closedir(*dir);
    if (tek->old_states == MENU)
        tek->states = LIST_MAP;
    else if (tek->old_states == EDITOR_MENU)
        tek->states = EDIT_MAP;
    else
        exit(84);
    buttons(&tek->files.btn, func, pos, name);
    tek->files.sprite = sfSprite_create();
    tek->files.texture = sfTexture_createFromFile("res/Background.png", NULL);
    sfSprite_setTexture(tek->files.sprite, tek->files.texture, sfTrue);
    sfSprite_setScale(tek->files.sprite, (sfVector2f){x, y});
}

void create_list(tekmaker_t *tek)
{
    struct dirent *dirent;
    sfVector2f textpos = {50.0, 50.0};
    int *ind = malloc(sizeof(int) * 2);
    DIR *dir = opendir("./maps");

    if (tek->files.files != NULL)
        free_list(&tek->files);
    ind[0] = 1;
    ind[1] = 0;
    if (dir == NULL)
        exit(84);
    while ((dirent = readdir(dir)) != 0) {
        if (dirent->d_name[0] == '.')
            continue;
        tek->files.files = fill_struct_files(tek->files.files,
        dirent->d_name, textpos);
        fill_list(ind, &textpos);
    }
    complete_struct_and_change_menu(tek, &dir);
}