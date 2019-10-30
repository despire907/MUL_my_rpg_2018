/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_root.h"
#include "resources_typedef.h"

int my_strcmp(char const *s1, char const *s2);

void register_rsc_root(root_t *root, resource_t *childs)
{
    int i = 0;

    while (root_pool[i].type != tp_null && my_strcmp(root_pool[i].name,
            root->name))
        ++i;
    if (root_pool[i].type == tp_root) {
        root_pool[i].data = root;
        root_pool[i].child = childs;
    }
}

void *construct_tp_root(xml_node_t *elem)
{
    root_t *root = malloc(sizeof(root_t));
    xml_node_t *dom;

    if (!root)
        return NULL;
    if (!(dom = get_dom_from_file(get_attributes_dom(elem->attributes,
            "path"))))
        return NULL;
    if (!(root->pools = construct_element_from_node(dom)))
        return NULL;
    root->name = get_attributes_dom(elem->attributes, "type");
    register_rsc_root(root, root->pools);
    return root;
}