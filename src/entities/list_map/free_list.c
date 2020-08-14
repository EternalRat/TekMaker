/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** free_list
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_list(list_files_t * files)
{
    int count = 0;

    for (; files; files = files->next, count++);
    return (count);
}

void destroy_list(list_files_t **elem, int count)
{
    list_files_t *todelete;

    if (elem == NULL)
        return;
    if (count > 1) {
        todelete = *elem;
        *elem = todelete->next;
        free(todelete);
    } else if (count == 1) {
        free(*elem);
        *elem = NULL;
    }
}

void free_list(files_t *files)
{
    int count = count_list(files->files);

    for (list_files_t *file = files->files; file; file = file->next) {
        free(file->name);
        free(file->path);
        sfTexture_destroy(file->texture);
        sfSprite_destroy(file->sprite);
        sfText_destroy(file->text);
    }
    for (; count != 0; count--)
        destroy_list(&files->files, count);
    sfTexture_destroy(files->texture);
    sfSprite_destroy(files->sprite);
    destroy_button(files->btn);
    files->files = NULL;
}