/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "resources.h"
#include "resources_typedef.h"
#include "tp_root.h"

int my_strcmp(char const *s1, char const *s2);

resource_key_t get_resource_key(char *key)
{
    int i = 0;

    while (xml_template[i].type != tp_null && my_strcmp(key,
            xml_template[i].key))
        ++i;
    return xml_template[i];
}

int count_node_number(xml_node_t *elem)
{
    int i = 0;

    while (elem) {
        ++i;
        elem = elem->next;
    }
    return i;
}

resource_t new_element_from_node(xml_node_t *elem)
{
    resource_key_t resource = get_resource_key(elem->element);
    resource_t rsc;

    rsc.data = resource.constructor(elem);
    if (!rsc.data) {
        rsc.type = tp_error;
        rsc.name = NULL;
    } else {
        rsc.type = resource.type;
        rsc.name = get_value_from_attributes(elem->attributes, "name");
        if (elem->child)
            rsc.child = construct_element_from_node(elem->child);
        else if (rsc.type == tp_root)
            rsc.child = ((root_t *)rsc.data)->pools;
        else
            rsc.child = NULL;
    }
    return rsc;
}

resource_t *construct_element_from_node(xml_node_t *elem)
{
    int child_nb = count_node_number(elem);
    resource_t *resource = NULL;
    int i = 0;

    if (!elem || !child_nb)
        return NULL;
    if (!(resource = malloc(sizeof(resource_t) * (child_nb + 1))))
        return NULL;
    while (elem && i < child_nb) {
        resource[i].type = tp_null;
        resource[i] = new_element_from_node(elem);
        elem = elem->next;
        ++i;
    }
    resource[child_nb].type = tp_null;
    return resource;
}