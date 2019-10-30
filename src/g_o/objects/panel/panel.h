/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MY_RPG_PANEL_H
#define MY_RPG_PANEL_H
#include "types.h"
#include "../../include/game_object.h"

struct s_go_panel{
    g_o_type_t type;
    int id;
};

void *new_panel(void);
void *reset_panel(void *source, void *value);
void destroy_panel(void *panel);
#endif //MY_RPG_PANEL_H
