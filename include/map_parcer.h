/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map parcer macros
*/

#ifndef MAP_H
#define MAP_H

typedef struct map_s {
        int line;
        int column;
        char **map;
}map_t;

char *get_next_line(const int fd);

void tab_print(char **tab);
int my_strlen(char *str);
int line_finder(int fd);
int map_finder(int fd);
char **map_filler(int fd, map_t *my_map);
int struct_map_parcer(char *filename);
map_t *size_filler(int fd);

#endif