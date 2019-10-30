/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** Created by Croquette,
*/

#include "xml.h"

void destroy_node_attributes(kv_t *attributes)
{
    kv_t *tmp = NULL;

    while (attributes) {
        tmp = attributes;
        attributes = attributes->next;
        free(tmp);
    }
}

void destroy_xml_node(xml_node_t *node)
{
    free(node->element);
    destroy_node_attributes(node->attributes);
}

void destroy_xml_dom(xml_node_t *node)
{
    xml_node_t *tmp;

    while (node) {
        tmp = node;
        if (node->child)
            destroy_xml_dom(node->child);
        node = node->next;
        destroy_xml_node(tmp);
    }
}