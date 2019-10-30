/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.h
*/

#ifndef MUL_MY_RPG_2018_GAME_OBJECT_H
#define MUL_MY_RPG_2018_GAME_OBJECT_H

#include <stdlib.h>
#include "../../system/image/position.h"
#include "types.h"

enum e_g_o_type{GOEmpty, GOPanel, GOEnd};

enum e_g_o_flag{FLAG_NULL = 0, EX_EVENT = 1, EX_PROCESS = 2, EX_EP = 4,
                EX_RENDER = 8, EX_ER = 16, EX_PR = 32, EX_ALL = 64};


struct s_game_object{
    g_o_type_t type;
    int id;
    enum e_g_o_flag flag;
    object_handlers_t *handlers;
    void *components;
    void *data;
    struct s_game_object *child;
    struct s_game_object *parent;
    position_t pos;
};
void *new_game_object(void);
void *reset_game_object(void *source, void *value);
void destroy_game_object(void *obj);
#endif //MUL_MY_RPG_2018_GAME_OBJECT_H
