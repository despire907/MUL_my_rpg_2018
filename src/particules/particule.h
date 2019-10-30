/*
** EPITECH PROJECT, 2018
** bla
** File description:
** bla
*/

#ifndef MY_RPG_PARTICULE_H
#define MY_RPG_PARTICULE_H

#include <SFML/Graphics/Types.h>
#include <SFML/Audio.h>

struct s_particule{
    sfVertexArray vertex;
    sfVector2u pos;
    sfVector2f vector;
    int lapse;
};

struct s_particule_field{
    struct s_particule *array;
    int nb_elem;
};

#endif //MY_RPG_PARTICULE_H
