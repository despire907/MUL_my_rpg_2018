/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MY_RPG_EVENT_H
#define MY_RPG_EVENT_H

#include <SFML/Window.h>

struct s_game_event{
    sfEvent *data;
    int type;
    void *pointer;
};

#endif //MY_RPG_EVENT_H
