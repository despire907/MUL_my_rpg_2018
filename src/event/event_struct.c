/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <step_machine.h>
#include "event_struct.h"
#include "types.h"

sfEvent *pop_window_event(sfRenderWindow *window)
{
    sfEvent *event = NULL;

    if (!window || sfRenderWindow_pollEvent(window, event) == sfFalse)
        return NULL;
    return event;
}

g_event_t *get_new_g_event(sfEvent *data)
{
    g_event_t *new_elem = NULL;

    if (!data || !(new_elem = malloc(sizeof(g_event_t))))
        return NULL;
    new_elem->data = data;
    new_elem->type = data->type;
    new_elem->pointer = NULL;
    return new_elem;
}