/*
** EPITECH PROJECT, 2018
** bla
** File description:
** bla
*/

#include <stdlib.h>
#include "vertex.h"

sfVertex get_vertex(int x, int y, sfColor color)
{
    sfVertex new_elem;
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    new_elem.position = pos;
    new_elem.color = color;
    return new_elem;
}

sfVertexArray *get_vertex_line(int size, sfColor color)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex x = get_vertex(0, 0, color);
    sfVertex width = get_vertex(0, size, color);

    sfVertexArray_append(array, x);
    sfVertexArray_append(array, width);
    return array;
}

sfVertexArray *get_vertex_triangle(int size, sfColor color)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex x = get_vertex(0, 0, color);
    sfVertex width = get_vertex(0, size, color);
    sfVertex corner = get_vertex(size / 2, size, color);

    sfVertexArray_append(array, x);
    sfVertexArray_append(array, width);
    sfVertexArray_append(array, corner);
    return array;
}

sfVertexArray *get_vertex_quad(int size, sfColor color)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex x = get_vertex(0, 0, color);
    sfVertex y = get_vertex(0, size, color);
    sfVertex width = get_vertex(size, 0, color);
    sfVertex height = get_vertex(size, size, color);

    sfVertexArray_append(array, x);
    sfVertexArray_append(array, y);
    sfVertexArray_append(array, width);
    sfVertexArray_append(array, height);
    return array;
}

sfVertexArray *get_vertex_shape(int shape, int size, sfColor color)
{
    sfVertexArray *(*shapes[3])(int, sfColor) = {&get_vertex_line,
                                                        &get_vertex_triangle,
                                                        &get_vertex_quad};
    return shapes[shape](size, color);
}