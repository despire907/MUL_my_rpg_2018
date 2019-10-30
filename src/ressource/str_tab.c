/*
** EPITECH PROJECT, 2018
** my_str_to_word
** File description:
** task4
*/

#include <stdlib.h>
#include <string.h>

int my_strlen(char const *str);

int is_not_word(char c, char *key)
{
    while (*key) {
        if (c == *key)
            return (0);
        ++key;
    }
    return (1);
}

int word_count(char const *str, char *key)
{
    int i = 0;
    int count = 0;
    int stack = 0;

    while (str[i]) {
        while (!is_not_word(str[i], key) && str[i] && str[i] != '\"')
            ++i;
        if (str[i] == '\"')
            ++stack;
        while (str[i] && ((is_not_word(str[i], key)) || stack % 2 == 1)) {
            if (!str[i + 1] || !is_not_word(str[i +1], key))
                ++count;
            if (str[i] == '\"')
                ++stack;
            ++i;
        }
    }
    return (count);
}

char *my_strdup_until_key(char const *str, char *key)
{
    char *dest;
    int i = 0;

    while (str[i] && (is_not_word(str[i], key) == 1))
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if (!dest)
        return NULL;
    i = 0;
    while (str[i] && (is_not_word(str[i], key) == 1)) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

char *duplicate_single_attribute(char const *str, int *i, char *key)
{
    char *dest;

    if (str[*i] == '\"') {
        dest =  my_strdup_until_key(&str[++*i], "\"");
        ++*i;
    } else
        dest = my_strdup_until_key(&str[*i], key);
    return dest;
}

char **duplicate_attributes(char const *str, char *key)
{
    char **tab = malloc(sizeof(char *) * (word_count(str, key) + 1));
    int len = my_strlen(str);
    int tab_index = 0;
    int i = 0;

    if (!tab)
        return NULL;
    while (i < len - 3) {
        while (str[i] && !is_not_word(str[i], key))
            i++;
        tab[tab_index] = duplicate_single_attribute(str, &i, key);
        if (!tab[tab_index])
            return NULL;
        i += my_strlen(tab[tab_index]);
        ++tab_index;
    }
    tab[tab_index] = NULL;
    return tab;
}