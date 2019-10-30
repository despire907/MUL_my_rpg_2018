/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include "../g_o/include/object_handlers.h"
#include "types.h"

void *alloc_new_object(g_o_type_t type)
{
    object_constructor constructor;

    if (type >= GOEnd || type < 0)
        return NULL;
    constructor = OBJECT_HANDLERS[type].constructor;
    return constructor();
}

void *reset_object_from_value(void *obj, void *value)
{
    object_setter setter;
    mask_t *item = (mask_t *)obj;

    if (!obj)
        return NULL;
    if (item->type >= GOEnd || item->type < 0)
        return NULL;
    setter = OBJECT_HANDLERS[item->type].setter;
    return setter(obj, value);
}

void destroy_object(void *obj)
{
    object_destructor destructor;
    mask_t *item = (mask_t *)obj;

    if (obj && !(item->type >= GOEnd || item->type < 0)) {
        destructor = OBJECT_HANDLERS[item->type].destructor;
        destructor(obj);
    }
}