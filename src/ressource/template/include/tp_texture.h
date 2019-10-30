/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** PSU_my_sokoban_2018 project
*/


#ifndef MUL_MY_RPG_2018_TP_TEXTURES_H
#define MUL_MY_RPG_2018_TP_TEXTURES_H


#include <SFML/Graphics.h>
#include "resources_typedef.h"
#include "xml.h"

struct s_tp_texture{
    char *name;
    sfTexture *texture;
    sfVector2u *size;
};

struct s_tp_animated_texture{
    char *name;
    sfTexture **textures;
    sfVector2u *size;
};

sfIntRect get_rect_dom(kv_t *attributes);
sfTexture *get_texture_dom(kv_t *attributes);
sfTexture **get_anim_textures_dom(kv_t *attributes);
void *construct_tp_texture(xml_node_t *elem);
void *construct_tp_texture_anim(xml_node_t *elem);
#endif //MUL_MY_RPG_2018_TP_TEXTURES_H
