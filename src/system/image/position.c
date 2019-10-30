/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** position function
*/

#include "position.h"

void reset_position(position_t *position)
{
    position->position.x = 0;
    position->position.y = 0;
    position->mode.x = 0;
    position->mode.y = 0;
}