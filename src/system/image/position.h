/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** position macros
*/


#ifndef MY_RPG_POSITION_H
#define MY_RPG_POSITION_H
#include <SFML/Graphics.h>

struct s_pos_mode{
    sfBool x;
    sfBool y;
};
typedef struct s_position{
    sfVector2f position;
    struct s_pos_mode mode;
} position_t;

void reset_position(position_t *position);
#endif //MY_RPG_POSITION_H
