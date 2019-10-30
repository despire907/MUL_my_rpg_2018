/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include <stdio.h>
#include "pool.h"

pool_t *pools_trick(pool_t *new_pools, int flag)
{
    static pool_t *pools = NULL;

    if (!flag) {
        pools = new_pools;
    }
    return pools;
}

pool_t *get_pools(void)
{
    return pools_trick(NULL, 1);
}