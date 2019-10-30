/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <stdio.h>
#include "hit/chang_color.h"

sfRenderWindow *window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1026, 728, 32};

    window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose,
            NULL);
    return window;
}

sfSprite *init_sprite(char *str)
{
    sfTexture *texture = sfTexture_createFromFile(str, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int i = 0;
    sfEvent event;
    sfRenderWindow *window = window_create();
    sfSprite *sprite = init_sprite("ton image");
    sfRenderWindow_setFramerateLimit(window, 30);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return (84);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        i++;
    }
    return 0;
}