/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <stdlib.h>
#include "resources.h"
#include "../../include/objects_types.h"
#include "panel.h"

void *new_panel(void)
{
    go_panel_t *panel = malloc(sizeof(go_panel_t));

    if (!panel)
        return NULL;
    panel->type = GOPanel;
    return panel;
}

void *reset_panel(void *source, void *value)
{
    go_panel_t *panel = (go_panel_t *)source;
    tp_panel_t *model = (tp_panel_t *)value;
}

void destroy_panel(void *panel)
{
    go_panel_t *elem = (go_panel_t *)panel;

    if (elem)
        free(elem);
}