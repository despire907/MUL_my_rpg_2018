/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RPG_2018_TP_TOWER_H
#define MUL_MY_RPG_2018_TP_TOWER_H

#include "resources.h"

struct s_tp_tower{
    char *name;
    char *type;
    sfTexture *texture;
    int hp;
    int atk_speed;
    char *projectile;
};

struct s_tp_wall{
    char *name;
    sfTexture *texture;
    int hp;
};

#endif //MUL_MY_RPG_2018_TP_TOWER_H
