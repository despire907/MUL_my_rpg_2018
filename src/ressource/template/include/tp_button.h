/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#ifndef MUL_MY_RPG_2018_TP_BUTTON_H
#define MUL_MY_RPG_2018_TP_BUTTON_H
#include <SFML/Graphics.h>
#include "resources_typedef.h"

struct s_tp_button{
    tp_texture_t *texture;
    tp_texture_t *hover;
    tp_texture_t *triggered;
    sfIntRect pos;
    event_node_t event;
};
#endif //MUL_MY_RPG_2018_TP_BUTTON_H
