/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** parser_texture
*/

#include "tekmaker.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void check_ext(char *path)
{
    int length = 0;
    char *ext[] = {".jpg", ".png", ".jpeg", NULL};

    for (int i = 0; ext[i]; i++) {
        length = strlen(path) - strlen(ext[i]);
        if (strcmp(&path[length], ext[i]) == 0)
            return;
    }
    printf("Something went wrong, verify your file for the texture.\n");
    exit(84);
}

void check_id(char id)
{
    char *authorized = "123456789ABCEFGH";

    for (int i = 0; authorized[i]; i++)
        if (authorized[i] == id)
            return;
    printf("Something went wrong, verify your ID into your texture file\n");
    exit(84);
}

int count_word_inarray(char **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    for (; array[i] != NULL; i++);
    return (i);
}

texture_t *create_path(texture_t *path, char *str)
{
    texture_t *texture = malloc(sizeof(texture_t));
    texture_t *tmp = NULL;
    char **array = my_str_to_wordarray(str, ';');

    if (texture == NULL)
        exit(84);
    if (count_word_inarray(array) != 2 || strlen(array[0]) != 1 ||
        strlen(array[1]) < 6)
        exit(84);
    if (access(array[1], F_OK) == -1)
        exit(84);
    texture->id = array[0][0];
    texture->path = strdup(array[1]);
    texture->next = NULL;
    if (path == NULL)
        return (texture);
    tmp = path;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = texture;
    return (path);
}

void parser_texture(char *file, tekmaker_t *tekmaker)
{
    FILE *stream = fopen(file, "r");
    texture_t *tmp = NULL;
    size_t n = 0;
    char *buffer = NULL;

    if (stream == NULL)
        exit(84);
    tekmaker->editor.path = NULL;
    while (getline(&buffer, &n, stream) != -1)
        tekmaker->editor.path = create_path(tekmaker->editor.path, buffer);
    tmp = tekmaker->editor.path;
    for (; tmp != NULL; tmp = tmp->next) {
        check_ext(tmp->path);
        check_id(tmp->id);
    }
}