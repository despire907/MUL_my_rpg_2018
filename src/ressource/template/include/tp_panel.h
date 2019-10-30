/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RPG_2018_TP_PANEL_H
#define MUL_MY_RPG_2018_TP_PANEL_H

#include "resources.h"

struct s_tp_panel{
    char *name;
    char *texture;
    sfIntRect rect;
    sfIntRect modulo_rect;
    resource_t *childs;
};

sfIntRect get_modulo_rect(kv_t *attributes);
int my_is_in_str(char *str, char c);

#endif //MUL_MY_RPG_2018_TP_PANEL_H
