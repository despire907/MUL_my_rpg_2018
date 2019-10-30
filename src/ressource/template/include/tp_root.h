/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RPG_2018_TP_ROOT_H
#define MUL_MY_RPG_2018_TP_ROOT_H

#include "resources.h"

struct s_resource_root{
    char *name;
    resource_t *pools;
    xml_node_t *dom;
};
#endif //MUL_MY_RPG_2018_TP_ROOT_H
