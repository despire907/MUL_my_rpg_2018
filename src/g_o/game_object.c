/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** game_object.c
*/

#include <stdlib.h>
#include "types.h"
#include "include/game_object.h"

void *new_game_object(void) {
    g_o_t *new_elem = malloc(sizeof(g_o_t));

    if (!new_elem)
        return NULL;
    new_elem->type = GOEmpty;
    return new_elem;
}

void *reset_game_object(void *source, void *value)
{
    g_o_t *obj = (g_o_t *)source;
    if (!obj)
        return NULL;
    obj->flag = FLAG_NULL;
    obj->id = 0;
    obj->child = NULL;
    obj->parent = NULL;
    obj->handlers = NULL;
    obj->components = NULL;
    reset_position(&obj->pos);
    return obj;
}

void destroy_game_object(void *obj)
{
    g_o_t *elem = (g_o_t *)obj;

    if (elem)
        free(elem);
}