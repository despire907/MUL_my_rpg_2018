/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_weapon.h"

#include "resources.h"
#include "xml.h"

void *construct_tp_weapon_melee(xml_node_t *elem)
{
    tp_weapon_melee_t *new_elem = malloc(sizeof(tp_weapon_melee_t));
    char *texture_name = get_value_from_attributes(elem->attributes,
            "texture");

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = search_for_resource("Texture", "TextureWeapon",
                                            texture_name);
    new_elem->damage = my_atoi(get_value_from_attributes(elem->attributes,
            "damage"));

    return new_elem;
}

void *construct_tp_weapon_range(xml_node_t *elem)
{
    tp_weapon_range_t *new_elem = malloc(sizeof(tp_weapon_range_t));
    char *texture_name = get_value_from_attributes(elem->attributes,
            "texture");

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = search_for_resource("Texture", "TextureWeapon",
                                            texture_name);
    new_elem->range = my_atoi(get_value_from_attributes(elem->attributes,
            "range"));
    new_elem->projectile = get_value_from_attributes(elem->attributes,
            "projectile");

    return new_elem;
}

void *construct_tp_projectile(xml_node_t *elem)
{
    tp_projectile_t *new_elem = malloc(sizeof(tp_projectile_t));
    char *texture_name = get_value_from_attributes(elem->attributes,
            "texture");

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->texture = search_for_resource("Texture", "TextureWeapon",
                                            texture_name);
    new_elem->mov_speed = my_atoi(get_value_from_attributes(elem->attributes,
            "mov_speed"));
    new_elem->damage = my_atoi(get_value_from_attributes(elem->attributes,
            "damage"));

    return new_elem;
}