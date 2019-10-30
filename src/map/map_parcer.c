/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map parcer function
*/

#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "../../include/map_parcer.h"

int my_strlen(char const *str);
int my_atoi(char const *str);
int my_strcmp_start(char const *s1, char const *s2);

int line_finder(int fd)
{
    char *temp;
    int final = 0;

    temp = get_next_line(fd);
    while (my_strcmp_start(temp, "size:") > 0) {
        free(temp);
        temp = get_next_line(fd);
    }
    if (my_strcmp_start(temp, "size:") <= 0)
        final = my_atoi(&temp[5]);
    else
        return -1;
    free(temp);
    return final;
}

map_t *size_filler(int fd)
{
    map_t *new = malloc(sizeof(map_t));
    int line = 0;

    if (new == NULL)
        return NULL;
    line = line_finder(fd);
    if (line == -1)
        return NULL;
    new->line = line;
    new->map = map_filler(fd, new);
    if (new->map == NULL)
        return NULL;
    new->column = my_strlen(new->map[0]);
    return new;
}

int map_finder(int fd)
{
    char *temp = get_next_line(fd);

    if (temp[0] == '\0')
        return 1;
    return 0;
}

char **map_filler(int fd, map_t *my_map)
{
    char **map = malloc(sizeof(char *) * (my_map->line + 2));
    int count = 0;

    if (map == NULL)
        return NULL;
    map_finder(fd);
    while (count <= my_map->line) {
        map[count] = get_next_line(fd);
        count = count + 1;
    }
    map[count] == NULL;
    return map;
}

int struct_map_parcer(char *filename)
{
    int fd = open(filename, O_RDONLY);
    map_t *my_map;

    if (fd < 0)
        return  84;
    my_map = size_filler(fd);
    if (my_map == NULL)
        return 84;
    return 0;
}