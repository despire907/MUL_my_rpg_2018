/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** PSU_my_sokoban_2018 project
*/


#ifndef MUL_MY_RPG_2018_OPEN_FILE_H
#define MUL_MY_RPG_2018_OPEN_FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct error
{
    int code;
    char *msg;
} error;

static struct error stat_errors[] =
{
    {S_IRUSR    , "Error -> file unreadable\n"          },
    {__S_IFREG  , "Error -> file isn't a regular file\n"},
    {-1  , "End"},
};

FILE *fs_f_open_file(char const *filepath);


typedef struct s_str_ll
{
    char *str;
    struct s_str_ll *next;
} strll_t;

void my_putchar_error(char c);
void my_putstr_error(char const *str);
char *fs_get_line(FILE *stream);
strll_t *read_file(char *path);
#endif