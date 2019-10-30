/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "xml.h"

int my_strcmp(char const *s1, char const *s2);

char *get_value_from_attributes(kv_t *attributes, char *key)
{
    kv_t *parse = attributes;

    while (parse) {
        if (my_strcmp(key, parse->key) == 0)
            return my_strdup(parse->value);
        parse = parse->next;
    }
    return NULL;
}

sfVector2u *get_size_dom(kv_t *attributes)
{
    sfVector2u *size = malloc(sizeof(sfVector2u));
    int x;
    int y;

    if (!size)
        return NULL;
    x = my_atoi(get_value_from_attributes(attributes, "width"));
    y = my_atoi(get_value_from_attributes(attributes, "height"));
    if (x < 0)
        x = 0;
    if (y < 0 )
        y = 0;
    size->x = (unsigned int)x;
    size->y = (unsigned int)y;

    return size;
}

sfIntRect get_rect_dom(kv_t *attributes)
{
    sfIntRect rect;

    rect.top = my_atoi(get_value_from_attributes(attributes, "x"));
    rect.left = my_atoi(get_value_from_attributes(attributes, "y"));
    rect.width = my_atoi(get_value_from_attributes(attributes, "width"));
    rect.height = my_atoi(get_value_from_attributes(attributes, "height"));
    return rect;
}

void *get_attributes_dom(kv_t *attributes, char *key)
{
    if (!my_strcmp(key, "size"))
        return get_size_dom(attributes);
    return get_value_from_attributes(attributes, key);
}
