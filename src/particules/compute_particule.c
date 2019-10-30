/*
** EPITECH PROJECT, 2018
** bla
** File description:
** bla
*/

#include "particule.h"

void compute_particule_field(part_t *field)
{
    int i = 0;

    while (field[i].vertex != 0) {
        if (field[i].lapse > 0) {
            field[i].pos.x += (unsigned int)field[i].vector.x;
            field[i].pos.y += (unsigned int)field[i].vector.y;
            field[i].lapse -= 1;
        }
        i++;
    }
}

void draw_particule_field(part_t *field, sfRenderTexture *texture)
{
    int i = 0;

    while (field[i].vertex != 0) {
        if (field[i].lapse > 0)
            sfRenderTexture_drawVertexArray(texture, field[i].vertex, NULL);
        i++;
    }
}