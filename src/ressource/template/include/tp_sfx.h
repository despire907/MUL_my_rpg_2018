/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** xml header
*/

#ifndef MUL_MY_RPG_2018_TP_SFX_H
#define MUL_MY_RPG_2018_TP_SFX_H

#include "resources.h"
#include "xml.h"

struct s_tp_sound{
    char *name;
    sfSound *sound;
};

struct s_tp_music{
    char *name;
    sfMusic *music;
    sfTime duration;
};

void *construct_tp_sound(xml_node_t *elem);
void *construct_tp_music(xml_node_t *elem);
#endif
