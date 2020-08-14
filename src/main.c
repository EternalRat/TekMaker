/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** main
*/

#include "tekmaker.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_help(void)
{
    printf("Usage:\n\t./tekmaker [files]\n");
    printf("\tfiles: configuration files for texture\n");
    exit(84);
}

int main(int ac, char **av)
{
    tekmaker_t tek;
    sfClock *clock = sfClock_create();

    if (ac != 2)
        print_help();
    if (access("res/goomba.png", F_OK) == -1 ||
    access("res/bill.png", F_OK) == -1 ||
    access("res/player.png", F_OK) == -1) {
        return (84);
    }
    init_tek(&tek, av[1]);
    sfRenderWindow_setFramerateLimit(tek.windows.window,
    tek.windows.settings.fps);
    srand(time(NULL));
    while (sfRenderWindow_isOpen(tek.windows.window)) {
        while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 20);
        loop(&tek);
        sfClock_restart(clock);
    }
    destroy_all(&tek);
    return (0);
}