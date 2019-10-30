/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** xml header
*/

#ifndef MUL_MY_DEFENDER_2018_XML_H
#define MUL_MY_DEFENDER_2018_XML_H
#include <string.h>
#include <SFML/Graphics.h>
#include "open_file.h"

typedef struct s_key_value{
    char *key;
    char *value;
    struct s_key_value *next;
}kv_t;

char **my_str_to_word_array_xml(char *str);
char *my_strdup(char const *src);
char **duplicate_attributes(char const *str, char *key);
int my_is_alphanumeric(char c);
int my_strcmp(char const *s1, char const *s2);
int get_nb_words_xml(char *str);
int verify_xml_line(char *buf);
int verify_xml_file(char *path);
int is_not_word(char c, char *key);
int word_count(char const *str, char *key);
int my_atoi(char *str);
sfIntRect get_rect_dom(kv_t *attributes);

typedef struct s_xml_node{
    char *element;
    struct s_key_value *attributes;
    struct s_xml_node *child;
    struct s_xml_node *next;
}xml_node_t;

int count_node_number(xml_node_t *elem);
char *get_value_from_attributes(kv_t *attributes, char *key);
void *get_attributes_dom(kv_t *attributes, char *key);
sfVector2u *get_size_dom(kv_t *attributes);

void get_node_info_from_line(xml_node_t *node, char *line);
xml_node_t *new_xml_node(void);
xml_node_t *get_node_from_stream(FILE *stream);
xml_node_t *get_dom_from_file(char *path);
#endif