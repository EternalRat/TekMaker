/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** count_image
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

int count_image(image_t *img)
{
    int count = 0;

    for (; img; img = img->next, count++);
    return (count);
}