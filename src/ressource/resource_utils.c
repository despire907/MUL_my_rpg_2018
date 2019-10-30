/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "resources.h"
#include "resources_typedef.h"
#include "tp_root.h"

root_t *resource_trick(root_t *new_pools, int flag)
{
    static root_t *pools = NULL;

    if (!flag) {
        pools = new_pools;
    }
    return pools;
}

root_t *get_resource_root(void)
{
    return resource_trick(NULL, 1);
}