/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <resources.h>
#include "xml.h"
#include "resources_typedef.h"
#include "include/tp_button.h"

void *construct_tp_button(xml_node_t *elem)
{
    tp_button_t *button;
    char *text_name = get_attributes_dom(elem->attributes, "img");
    char *hover_name = get_attributes_dom(elem->attributes, "hover");
    char *triggered_name = get_attributes_dom(elem->attributes, "triggered");

    if (!(button = malloc(sizeof(tp_button_t))))
        return NULL;
    button->pos = get_rect_dom(elem->attributes);
    button->texture = search_for_resource("Texture", "TexturesHud", text_name);
    button->hover = search_for_resource("Texture", "TexturesHud", hover_name);
    button->triggered = search_for_resource("Texture", "TexturesHud",
            triggered_name);
    button->event = NULL;
    return button;
}