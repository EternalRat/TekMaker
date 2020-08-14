/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** parser_key
*/

#include "parser/key.h"
#include "tekmaker.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const keys_t keys[] = {
    {0, "A"},
    {1, "B"},
    {2, "C"},
    {3, "D"},
    {4, "E"},
    {5, "F"},
    {6, "G"},
    {7, "H"},
    {8, "I"},
    {9, "J"},
    {10, "K"},
    {11, "L"},
    {12, "M"},
    {13, "N"},
    {14, "O"},
    {15, "P"},
    {16, "Q"},
    {17, "R"},
    {18, "S"},
    {19, "T"},
    {20, "U"},
    {21, "V"},
    {22, "W"},
    {23, "X"},
    {24, "Y"},
    {25, "Z"},
    {37, "CONTROL"},
    {57, "SPACE"},
    {39, "ALT"}
};

static void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void change_key(int key, key_config_t *conf, char *act)
{
    char *action[] = {"JUMP", "DOWN", "LEFT", "RIGHT", "FIRE",
        "EDITOR_RIGHT", "EDITOR_LEFT", NULL};
    int *change_key[] = {&conf->jump, &conf->down, &conf->left,
        &conf->right, &conf->fire, &conf->editor_right, &conf->editor_left};

    for (int i = 0; action[i]; i++)
        if (strcmp(act, action[i]) == 0)
            (*change_key)[i] = key;
}

int check_key(char **array, key_config_t *config)
{
    if (count_array(array) != 2) {
        free_array(array);
        return (1);
    }
    for (int i = 0; i != 29; i++) {
        if (strcmp(keys[i].config, array[1]) == 0) {
            change_key(keys[i].key, config, array[0]);
            free_array(array);
            return (0);
        }
    }
    return (1);
}

int parser_key(key_config_t *config, char *path)
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
        if (check_key(array, config))
            return (1);
    }
    free(buffer);
    fclose(stream);
    return (0);
}