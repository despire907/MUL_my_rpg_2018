/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "tp_scene.h"
#include "resources.h"

void *construct_tp_scene(xml_node_t *elem)
{
    tp_scene_t *new_elem = malloc(sizeof(tp_scene_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    return new_elem;
}

void destroy_tp_scene(void *scene)
{
    tp_scene_t *elem = (tp_scene_t *)scene;

    free(elem);
}