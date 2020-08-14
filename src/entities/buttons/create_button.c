/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** create_button
*/

#include "button.h"
#include <unistd.h>
#include <stdlib.h>

void button_display(button_t *buttons, sfRenderWindow *windows)
{
    for (; buttons; buttons = buttons->next) {
        event_btn_state(sfMouse_getPositionRenderWindow(windows), buttons);
        sfRenderWindow_drawSprite(windows, buttons->sprite, NULL);
        sfRenderWindow_drawText(windows, buttons->text, NULL);
    }
}

static void set_sprite(button_t *button, sfVector2f pos)
{
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile("res/textures/btn.png", NULL);
    button->intrect = (sfIntRect){0, 20, 200, 20};
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->intrect);
    sfSprite_setScale(button->sprite, (sfVector2f) {2, 4});
    sfSprite_setPosition(button->sprite, pos);
}

static void set_text(button_t *button, sfVector2f pos, char *str)
{
    button->font = sfFont_createFromFile("res/textures/SuperMario256.ttf");
    button->text = sfText_create();
    sfText_setString(button->text, str);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 40);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 40, pos.y + 15});
}

button_t *create_button(button_t **btn, char *str, sfVector2f pos,
void (*callback)(tekmaker_t *))
{
    button_t *button = malloc(sizeof(button_t));
    button_t *tmp;

    if (!button)
        return (NULL);
    set_sprite(button, pos);
    set_text(button, pos, str);
    button->callback = callback;
    button->next = NULL;
    if (!button->sprite || !button->text)
        exit(84);
    if (*btn == NULL)
        return (button);
    tmp = *btn;
    for (; tmp->next; tmp = tmp->next);
    tmp->next = button;
    return (*btn);
}

void buttons(button_t **buttons, void (**callback)(tekmaker_t *),
sfVector2f pos, char **name)
{
    (*buttons) = NULL;
    for (int i = 0; name[i]; i++) {
        (*buttons) = create_button(buttons, name[i], pos, callback[i]);
        pos.y += 100;
    }
}