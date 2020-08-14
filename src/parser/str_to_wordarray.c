/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str_to_wordarray
*/

#include <stdlib.h>

int count_words(char *str, char sep)
{
    int words = 1;
    int i = 0;

    while (str[i]) {
        if (str[i] == sep || str[i] == '\0')
            words++;
        i++;
    }
    return (words);
}

int count_each_line(char *str, char sep)
{
    int i = 0;

    for (; str[i] && str[i] != sep; i++);
    return (i);
}

char **my_str_to_wordarray(char *str, char sep)
{
    int len = count_words(str, sep);
    char **tab = NULL;

    if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    for (int i = 0, z = 0, j = 0; i < len; i++, j++, z = 0) {
        tab[i] = malloc(sizeof(char) * (count_each_line(&str[j], sep) + 1));
        for (; str[j] && str[j] != sep && str[j] != '\n'; z++, j++)
            tab[i][z] = str[j];
        tab[i][z] = '\0';
    }
    tab[len] = NULL;
    return (tab);
}