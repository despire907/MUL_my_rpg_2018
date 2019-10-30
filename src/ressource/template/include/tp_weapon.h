/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RPG_2018_TP_WEAPON_H
#define MUL_MY_RPG_2018_TP_WEAPON_H

#include "resources.h"

struct s_tp_projectile{
    char *name;
    sfTexture *texture;
    int mov_speed;
    int damage;
};

struct s_tp_weapon_melee{
    char *name;
    sfTexture *texture;
    int damage;
};

struct s_tp_weapon_range{
    char *name;
    sfTexture *texture;
    int range;
    char *projectile;
};
#endif //MUL_MY_RPG_2018_TP_WEAPON_H
