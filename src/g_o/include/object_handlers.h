/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MY_RPG_OBJECT_HANDLERS_H
#define MY_RPG_OBJECT_HANDLERS_H

#include <resources.h>
#include "game_object.h"
#include "types.h"
#include "../objects/panel/panel.h"



struct s_object_handlers{
    g_o_type_t type;
    int pool_size;
    template_t template;
    object_constructor constructor;
    object_setter setter;
    object_destructor destructor;
    object_handler handler;
};

typedef struct s_game_object_mask {
    enum e_g_o_type type;
    int id;
    enum e_g_o_flag flag;
} mask_t;

static object_handlers_t OBJECT_HANDLERS[] = {{GOEmpty, 16, tp_null,
                                                new_game_object,
                                                reset_game_object,
                                                destroy_game_object, NULL},
                                                {GOPanel, 16, tp_panel,
                                                new_panel, reset_panel,
                                                destroy_panel, NULL},
                                                {GOEnd, 0, tp_null, NULL, NULL,
                                                NULL}};

void *alloc_new_object(g_o_type_t type);
void *reset_object_from_value(void *obj, void *value);
void destroy_object(void *obj);
#endif //MY_RPG_OBJECT_HANDLERS_H
