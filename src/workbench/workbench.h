/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** workbench macros
*/

#ifndef MY_RPG_SCENE_H
#define MY_RPG_SCENE_H
#include "resources_typedef.h"
#include "tp_scene.h"

typedef struct s_workbench{
    char *name;
} workbench_t;

workbench_t *new_workbench(tp_scene_t *scene);
#endif //MY_RPG_SCENE_H
