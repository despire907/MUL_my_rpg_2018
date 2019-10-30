/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_pool.h"
#include "resources_typedef.h"

void *construct_tp_object_pool(xml_node_t *elem)
{
    tp_object_pool_t *new_elem = malloc(sizeof(tp_object_pool_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->pool = construct_element_from_node(elem->child);
    if (!new_elem->pool)
        return NULL;

    return new_elem;
}