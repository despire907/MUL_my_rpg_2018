/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#ifndef MY_RPG_POOL_H
#define MY_RPG_POOL_H
#include "types.h"
#include "../g_o/include/game_object.h"

typedef enum e_pool_obj_status{PoolObjectInUse, PoolObjectInactive,
                                PoolObjectUnallocated}pool_type_t;

typedef struct s_pool_obj{
    void *data;
    pool_type_t status;
}pool_obj_t;

typedef struct s_pool{
    int size;
    int elements_in_use;
    int elements_inactive;
    g_o_type_t type;
    pool_obj_t *objs;
}pool_t;


pool_t *init_pools(void);
void *realoc_pool(pool_t *pool);
pool_t *new_pool(pool_t *pool, g_o_type_t type, int size);
pool_obj_t *alloc_pool_obj(int size);
void destroy_pool_objs(pool_obj_t *objs, int size);
void destroy_pools(pool_t *pools);
pool_t *pools_trick(pool_t *new_pools, int flag);
pool_t *get_pools(void);
void obj_set_id(void *obj, int id);
void *new_object(g_o_type_t type);
void free_object(void **obj);
#endif //MY_RPG_POOL_H
