/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_texture.h"

void *construct_tp_texture(xml_node_t *elem)
{
    tp_texture_t *new_elem = malloc(sizeof(tp_texture_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = get_texture_dom(elem->attributes);
    new_elem->size = get_size_dom(elem->attributes);
    return new_elem;
}

void *construct_tp_texture_anim(xml_node_t *elem)
{
    tp_texture_anim_t *new_elem = malloc(sizeof(tp_texture_anim_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->textures = get_anim_textures_dom(elem->attributes);
    new_elem->size = get_size_dom(elem->attributes);
    return new_elem;
}