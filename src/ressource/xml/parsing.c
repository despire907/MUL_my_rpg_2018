/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** parsing xml
*/

#include "xml.h"

int my_strlen(char const *str);

int check_word(char *word, int *i)
{
    while (word[*i] && (word[*i] != ' ' && word[*i] != '\t')) {
        if (is_not_word(word[*i], " \t\n=\"<>/") == 0)
            return 84;
        *i = *i + 1;
    }

    return 0;
}

int check_attribute(char *attribute, int *i)
{
    while (attribute[*i] && attribute[*i] != '=') {
        if (is_not_word(attribute[*i], " \t\n=\"<>/") == 0)
            return 1;
        *i = *i + 1;
    }
    if (attribute[*i] != '=' || attribute[*i + 1] != '\"')
        return 84;
    *i = *i + 2;
    while (attribute[*i] && attribute[*i] != '\"')
        *i = *i + 1;
    if (!attribute[*i])
        return 84;
    *i = *i + 1;
    return 0;
}

int verify_xml_line(char *line)
{
    int i = 0;
    int len = my_strlen(line);
    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        i++;
    if (line[i] != '<' || (line[len - 2] != '>' && line[len - 1] != '>'))
        return 84;
    i++;
    if (line[i] == '/')
        i++;
    if (check_word(line, &i) == 1)
        return 84;
    while (line[i] && line[i] != '/' && line[i] != '>') {
        while (line[i] && (line[i] == ' ' || line[i] == '\t'))
            i++;
        if (check_attribute(line, &i) == 1) {
            return 84;
        }
    }return (!line[i] || (line[i] == '/' && (line[i + 1] != '>' ||
            line[i + 2] != '\n')) || (line[i] == '>' && (line[i + 1] != '\n' &&
            line[i + 1] != '\0'))) ? 84 : 0;
}

int verify_xml_file(char *path)
{
    FILE *stream = fs_f_open_file(path);
    char *line;

    if (!stream || !path[0])
        return 1;
    while ((line = fs_get_line(stream))) {
        if (verify_xml_line(line) == 84) {
            fclose(stream);
            return 84;
        }
        free(line);
    }
    fclose(stream);
    return 0;
}
