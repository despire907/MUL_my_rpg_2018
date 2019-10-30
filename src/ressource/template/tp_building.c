/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_building.h"

void *construct_tp_tower(xml_node_t *elem)
{
    tp_tower_t *new_elem = malloc(sizeof(tp_tower_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = get_attributes_dom(elem->attributes, "texture");
    new_elem->type = get_attributes_dom(elem->attributes, "type");
    new_elem->hp = my_atoi(get_value_from_attributes(elem->attributes,
            "hp"));
    new_elem->atk_speed = my_atoi(get_value_from_attributes(elem->attributes,
            "atk_speed"));
    new_elem->projectile = get_value_from_attributes(elem->attributes,
            "projectile");

    return new_elem;
}

void *construct_tp_wall(xml_node_t *elem)
{
    tp_wall_t *new_elem = malloc(sizeof(tp_wall_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = get_attributes_dom(elem->attributes, "texture");
    new_elem->hp = my_atoi(get_value_from_attributes(elem->attributes,
            "hp"));

    return new_elem;
}