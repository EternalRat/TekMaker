/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** button
*/

typedef struct button_s button_t;
#ifndef BUTTON_H_
#define BUTTON_H_

#include "tekmaker.h"

struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfFont *font;
    sfIntRect intrect;
    void (*callback)();
    button_t *next;
};

void button_display(button_t *buttons, sfRenderWindow *windows);
void buttons(button_t **buttons, void (**callback)(), sfVector2f pos,
char **name);
void event_btn_state(sfVector2i m_pos, button_t *btn);
int count_button(button_t * btn);
void destroy_button(button_t *btn);

#endif /* !BUTTON_H_ */