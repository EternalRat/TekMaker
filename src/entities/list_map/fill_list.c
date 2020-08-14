/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** fill_list
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>

void fill_list(int *ind, sfVector2f *pos)
{
    static int i = 0;

    if (ind[0] % 12 == 0 && ind[1] != 3) {
        i += 4;
        (*pos).y = -150;
    }
    if (ind[0] % 4 == 0 && ind[1] != 3) {
        (*pos).y += 200;
        (*pos).x = 50 + 300 * i;
        ind[1]++;
    } else
        (*pos).x += 300;
    ind[0]++;
}