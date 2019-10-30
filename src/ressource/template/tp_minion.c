/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_minion.h"

#include "resources.h"
#include "xml.h"

void *construct_tp_minion(xml_node_t *elem)
{
    tp_minion_t *new_elem = malloc(sizeof(tp_minion_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = get_attributes_dom(elem->attributes, "texture");
    new_elem->hp = my_atoi(get_value_from_attributes(elem->attributes,
            "hp"));
    new_elem->mov_speed = my_atoi(get_value_from_attributes(elem->attributes,
            "mov_speed"));
    new_elem->atk_speed = my_atoi(get_value_from_attributes(elem->attributes,
            "atk_speed"));
    new_elem->weapon = get_value_from_attributes(elem->attributes,
            "weapon");

    return new_elem;
}