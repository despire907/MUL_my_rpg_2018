/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "pool.h"
#include "../g_o/include/object_handlers.h"

pool_obj_t *get_pool_obj_by_id(g_o_type_t type, int id)
{
    pool_t *pools = get_pools();

    if (type > GOEnd || id > pools[type].size) {
        return (NULL);
    }
    if (pools[type].objs[id].status == PoolObjectInUse) {
        return &pools[type].objs[id];
    }
    return (NULL);
}

void *new_object(g_o_type_t type)
{
    pool_t *pools = get_pools();

    if (type >= GOEnd || type < 0)
        return NULL;
    return pool_get_new_obj(&pools[type]);
}

void *get_obj_by_id(g_o_type_t type, int id)
{
    pool_obj_t *pool_obj = get_pool_obj_by_id(type, id);

    if (pool_obj)
        return pool_obj->data;
    return (NULL);
}

void obj_set_id(void *obj, int id)
{
    mask_t *item = (mask_t *)obj;

    item->id = id;
}

void free_object(void **obj)
{
    mask_t *item = (mask_t *)(*obj);
    pool_t *pools = get_pools();
    pool_obj_t *pool_obj;

    if (item) {
        pool_obj = get_pool_obj_by_id(item->type, item->id);
        if (pool_obj) {
            --pools[item->type].elements_in_use;
            ++pools[item->type].elements_inactive;
            pool_obj->status = PoolObjectInactive;
            *obj = NULL;
        }
    }
}