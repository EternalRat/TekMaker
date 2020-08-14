/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** create_windows.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_windows(sfVideoMode mode)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, "TekMaker",
    sfClose, NULL);

    if (window == NULL)
        return (NULL);
    return (window);
}