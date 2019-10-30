/*
** EPITECH PROJECT, 2018
** bla
** File description:
** bla
*/

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "particule.h"
#include "vertex.h"
#include "types.h"

part_t get_new_particule(int shape, sfVector2u pos, sfVector2f vector,
        sfColor color)
{
    part_t new_elem;

    if (shape < 0 || shape > 2)
        shape = 0;
    new_elem.vertex = get_vertex_shape(shape, 10, color);
    new_elem.pos = pos;
    new_elem.vector = vector;
    new_elem.lapse = (rand() % 100) + 1;
    return new_elem;
}

part_t *get_new_particule_array(int nb_elem, int shape, sfColor color)
{
    int i = 0;
    part_t *new_elem;
    sfVector2u pos = {0, 0};
    sfVector2f vec = {0, 0};

    if (!nb_elem || !(new_elem = malloc(sizeof(part_t) * (nb_elem + 1))))
        return NULL;
    while (i < nb_elem) {
        new_elem[i] = get_new_particule(shape, pos, vec, color);
        i++;
    }
    new_elem[i].vertex = 0;
    return new_elem;
}

void set_random_part_array(part_t *array, sfIntRect pos, sfColor color)
{
    int i = 0;
    sfVector2u tmp_pos;
    sfVector2f tmp_vec;

    if (array) {
        while (array[i].vertex != 0) {
            array[i].pos.x = (unsigned int)pos.left + (rand() % pos.width);
            array[i].pos.y = (unsigned int)pos.top + (rand() % pos.height);
            array[i].vector.x = (tmp_pos.x % pos.width) *
                                                        (i % 2 == 0) ? -1 : 1;
            array[i].vector.y = (tmp_pos.y % pos.height) *
                                                        (i % 2 == 1) ? -1 : 1;
            i++;
        }
    }
}

void set_circle_part_array(part_t *array, sfIntRect pos, sfColor color,
        int nb_elem)
{
    int i = 0;
    sfVector2u tmp_pos;
    sfVector2f tmp_vec;

    if (array) {
        while (array[i].vertex != 0) {
            tmp_pos.x = (unsigned int)pos.left + (pos.width / 2);
            tmp_pos.y = (unsigned int)pos.top + (pos.height / 2);
            tmp_vec.x = (float)cos(((double)360 / nb_elem) * i) * 3;
            tmp_vec.y = (float)sin(((double)360 / nb_elem) * i) * 3;
            i++;
        }
    }
}