/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** workbench function
*/

#include "workbench.h"

workbench_t *new_workbench(tp_scene_t *scene)
{
    workbench_t *wb;

    if (!scene)
        return NULL;
    wb = malloc(sizeof(workbench_t));
    if (!wb)
        return NULL;
    return wb;
}