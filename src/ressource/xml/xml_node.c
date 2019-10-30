/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "xml.h"
#include "open_file.h"

int my_strlen(char const *str);

xml_node_t *new_xml_node(void)
{
    xml_node_t *elem = malloc(sizeof(xml_node_t));

    if (!elem)
        return NULL;
    elem->child = NULL;
    elem->next = NULL;
    return elem;
}

kv_t *new_elem_key_value(char *key, char *value)
{
    kv_t *elem = malloc(sizeof(kv_t));

    if (!elem)
        return NULL;
    elem->key = key;
    elem->value = value;
    elem->next = NULL;

    return elem;
}

void get_node_info_from_line(xml_node_t *node, char *line)
{
    char **tab_line = duplicate_attributes(line, " \t\n=<>/");
    int i = 1;
    kv_t *begin = NULL;
    kv_t *elem = NULL;

    node->element = tab_line[0];
    while (tab_line[i - 1] && tab_line[i]) {
        if (!begin) {
            begin = new_elem_key_value(tab_line[i], tab_line[i + 1]);
            elem = begin;
        } else {
            elem->next = new_elem_key_value(tab_line[i], tab_line[i + 1]);
            elem = elem->next;
        }
        i += 2;
    }
    node->attributes = begin;
}

int is_line_closing_closed(char const *line)
{
    int i = 0;
    size_t len;

    if (!line)
        return 0;
    len = my_strlen(line);
    while (line[i] && line[i] != '<')
        i++;
    if (line[i + 1] == '/')
        return 0;
    else if (line[len - 3] == '/' || line[len - 2] == '/')
        return 1;
    return 2;
}

xml_node_t *get_node_from_stream(FILE *stream)
{
    xml_node_t *node;
    char *line = fs_get_line(stream);
    int state = is_line_closing_closed(line);

    if (!stream || state == 0)
        return NULL;
    node = new_xml_node();
    get_node_info_from_line(node, line);
    if (state == 2)
        node->child = get_node_from_stream(stream);
    node->next = get_node_from_stream(stream);

    return node;
}