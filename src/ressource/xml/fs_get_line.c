/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** PSU_minishell1_2018 project
*/

#include <stdio.h>
#include <stdlib.h>

char *fs_get_line(FILE *stream)
{
    __ssize_t check = 0;
    char *buf = NULL;
    size_t buf_size = 0;

    if (!stream)
        return NULL;
    if ((check = getline(&buf, &buf_size, stream)) == 0)
        return NULL;
    if (check == -1) {
        free(buf);
        return NULL;
    }
    return buf;
}