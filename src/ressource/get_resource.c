/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "resources.h"
#include "resources_typedef.h"
#include "tp_root.h"

int my_strcmp(char const *s1, char const *s2);

resource_t *get_elem_by_name(resource_t *rsc, char *name)
{
    int i = 0;

    if (!rsc || !name)
        return NULL;
    while (rsc[i].type != tp_null && (my_strcmp(rsc[i].name, name)) != 0)
        i++;
    if (rsc[i].type == tp_null)
        return NULL;
    return &rsc[i];
}

void *search_for_resource(char *key, char *category, char *name)
{
    root_t *root = get_resource_root();
    resource_t *elem;
    int i = 0;

    if (!key || !category || !name || !root)
        return NULL;
    while (root[i].name && my_strcmp(root[i].name, key) != 0)
        ++i;
    if (!root[i].name)
        return NULL;
    if (!(elem = root[i].pools))
        return NULL;
    if (!(elem = get_elem_by_name(elem, category)))
        return NULL;
    if (!(elem = get_elem_by_name(elem->child, name)))
        return NULL;
    return elem->data;
}