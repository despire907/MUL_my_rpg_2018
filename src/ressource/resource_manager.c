/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <stdlib.h>
#include "resources.h"
#include "resources_typedef.h"
#include "tp_root.h"

int my_strcmp(char const *s1, char const *s2);

int fill_rsc_manager(root_t *root, xml_node_t *dom)
{
    if (!(root->dom = get_dom_from_file(get_attributes_dom(dom->attributes,
            "path")))) {
        return 0;
    } if (!(root->pools = construct_element_from_node(root->dom))) {
        return 0;
    }
    return 1;
}

xml_node_t *resource_manager_load_xml(char *path, int *nb)
{
    xml_node_t *dom;

    if (!(dom = get_dom_from_file(path)))
        return 0;
    *nb = count_node_number(dom);
    if (*nb <= 0) {
        return 0;
    }
    return dom;
}

int resource_manager_init(char *path)
{
    root_t *root;
    xml_node_t *dom;
    int nb;
    int i = 0;

    if (!(dom = resource_manager_load_xml(path, &nb)) ||
        !(root = malloc(sizeof(root_t) * (nb + 1))))
        return 0;
    resource_trick(root, 0);
    while (dom) {
        if (!my_strcmp(dom->element, "Root")) {
            if (!fill_rsc_manager(&root[i], dom))
                return 0;
            root[i].name = get_attributes_dom(dom->attributes, "type");
            ++i;
        }
        dom = dom->next;
    }
    root[i].name = NULL;
    root[i].pools = NULL;
    return 1;
}