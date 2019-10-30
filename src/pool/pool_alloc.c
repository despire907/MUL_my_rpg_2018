/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include <stdio.h>
#include "pool.h"
#include "../g_o/include/object_handlers.h"

pool_obj_t *alloc_pool_obj(int size)
{
    pool_obj_t *objs = malloc(sizeof(pool_obj_t) * size);
    int i = 0;

    if (!objs)
        return NULL;
    while (i < size) {
        objs[i].data = NULL;
        objs[i].status = PoolObjectUnallocated;
        ++i;
    }
    return objs;
}

pool_t *new_pool(pool_t *pool, g_o_type_t type, int size)
{
    if (size < 2) {
        return (NULL);
    }
    if (!(pool->objs = alloc_pool_obj(size))) {
        free(pool);
        return (NULL);
    }
    pool->type = type;
    pool->elements_in_use = 0;
    pool->elements_inactive = 0;
    pool->size = size;
    return (pool);
}

void *realoc_pool(pool_t *pool)
{
    pool_obj_t *objs = alloc_pool_obj(pool->size * 2);
    int i = 0;

    if (!objs) {
        return NULL;
    } while (i < pool->size) {
        objs[i] = pool->objs[i];
        ++i;
    }
    free(pool->objs);
    pool->objs = objs;
    pool->size *= 2;
    return pool;
}

pool_t *init_pools(void)
{
    int i = 0;
    pool_t *pools = malloc(sizeof(pool_t) * GOEnd);

    if (!pools)
        return (NULL);
    while (i < GOEnd) {
        if (!new_pool(&pools[i], OBJECT_HANDLERS[i].type,
                OBJECT_HANDLERS[i].pool_size))
            return (NULL);
        ++i;
    }
    pools_trick(pools, 0);
    return pools;
}