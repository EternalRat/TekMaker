/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** parser_key
*/

#include "parser/settings.h"
#include "tekmaker.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

static int check_settings(char **array, settings_t *settings)
{
    char *sett[] = {"FPS", "WIDTH", "HEIGHT", "X_LIMIT", "Y_LIMIT", NULL};
    int *setting[] = {&settings->fps, &settings->width, &settings->height,
        &settings->x_limit, &settings->y_limit};
    int min[] = {15, 800, 600, 10, 10};

    for (int i = 0; array[1][i]; i++)
        if (isdigit(array[1][i]) == 0)
            return (1);
    for (int i = 0; sett[i]; i++) {
        if (strcmp(array[0], sett[i]) == 0 && atoi(array[1]) >= min[i]) {
            (*setting)[i] = atoi(array[1]);
            free_array(array);
            return (0);
        }
    }
    return (1);
}

int parser_settings(settings_t *settings, char *path)
{
    FILE *stream = fopen(path, "r");
    size_t n = 0;
    char *buffer = NULL;
    char **array = NULL;

    if (stream == NULL)
        exit(84);
    while (getline(&buffer, &n, stream) != -1) {
        array = my_str_to_wordarray(buffer, ';');
        if (array == NULL)
            exit(84);
        if (count_array(array) != 2) {
            free_array(array);
            return (1);
        }
        if (check_settings(array, settings))
            return (1);
    }
    free(buffer);
    fclose(stream);
    return (0);
}