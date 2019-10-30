/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_panel.h"

#include "resources_typedef.h"
#include "xml.h"

sfIntRect get_modulo_rect_dom(kv_t *attributes)
{
    sfIntRect rect;

    if (my_is_in_str(get_value_from_attributes(attributes, "x"), '%'))
        rect.top = 1;
    else
        rect.top = 0;
    if (my_is_in_str(get_value_from_attributes(attributes, "y"), '%'))
        rect.left = 1;
    else
        rect.left = 0;
    if (my_is_in_str(get_value_from_attributes(attributes, "width"), '%'))
        rect.width = 1;
    else
        rect.width = 0;
    if (my_is_in_str(get_value_from_attributes(attributes, "height"), '%'))
        rect.height = 1;
    else
        rect.height = 0;
    return rect;
}

void *construct_tp_panel(xml_node_t *elem)
{
    tp_panel_t *new_elem = malloc(sizeof(tp_panel_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = get_attributes_dom(elem->attributes, "texture");
    new_elem->rect = get_rect_dom(elem->attributes);
    new_elem->modulo_rect = get_modulo_rect_dom(elem->attributes);
    new_elem->childs = construct_element_from_node(elem->child);

    return new_elem;
}