/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** CPE_matchstick_2018 project
*/

#include <string.h>

int my_strlen(char const *str);

int power(int a, int b)
{
    int i = 0;
    int dest = 1;

    while (i < b) {
        dest *= a;
        i++;
    }

    return dest;
}

int my_atoi(char *str)
{
    int i = 0;
    size_t len;
    int dest = 0;
    int minus = 1;

    if (!str)
        return 0;
    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-')
            minus *= -1;
        i++;
    }
    len = my_strlen(&str[i]) - 1;
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        dest += (str[i] - 48) * power(10, (int)len);
        len--;
        i++;
    }
    dest *= minus;
    return dest;
}
