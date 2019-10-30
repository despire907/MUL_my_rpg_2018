/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** task07
*/

int my_is_in_str(char *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}