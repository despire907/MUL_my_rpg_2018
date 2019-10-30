/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include "pool.h"
#include "../g_o/include/object_handlers.h"

void destroy_pool_objs(pool_obj_t *objs, int size)
{
    int i = 0;

    if (objs) {
        while (i < size) {
            if (objs[i].status != PoolObjectUnallocated)
                destroy_object(objs[i].data);
            ++i;
        }
        free(objs);
    }
}

void destroy_pools(pool_t *pools)
{
    int i = 0;

    if (pools) {
        while (i < GOEnd) {
            destroy_pool_objs(pools[i].objs, pools[i].size);
            ++i;
        }
        pools_trick(NULL, 0);
    }
}
