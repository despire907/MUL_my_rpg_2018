/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** CPE_BSQ_2018 project
*/

#include "open_file.h"

FILE *fs_f_open_file(char const *filepath)
{
    FILE *stream;

    if (!filepath)
        return NULL;
    stream = fopen(filepath, "r");
    if (!(stream))
        return NULL;
    return (stream);
}

xml_node_t *get_dom_from_file(char *path)
{
    FILE *stream;
    xml_node_t *dom = NULL;
    int check = verify_xml_file(path);

    if (check == 84)
        return NULL;
    if (!(stream = fs_f_open_file(path)))
        return NULL;
    dom = get_node_from_stream(stream);
    fclose(stream);

    return dom;
}