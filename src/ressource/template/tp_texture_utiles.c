/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_texture.h"
#include "resources_typedef.h"

sfTexture *get_texture_dom(kv_t *attributes)
{
    char *path = get_value_from_attributes(attributes, "path");
    sfTexture *texture;
    sfIntRect rect = get_rect_dom(attributes);

    if (!path) {
        texture = sfTexture_createFromFile("rsc/textures/error.jpg",
                NULL);
    } else
        texture = sfTexture_createFromFile(path, &rect);
    return texture;
}

sfVector2u get_texture_size_from_path(char *path)
{
    sfVector2u size;
    sfTexture *texture;

    if (!path) {
        texture = sfTexture_createFromFile(
                "rsc/textures/error.jpg", NULL);
    } else
        texture = sfTexture_createFromFile(path, NULL);
    size = sfTexture_getSize(texture);
    free(texture);

    return size;
}

sfTexture **get_anim_textures_dom(kv_t *attributes)
{
    char *path = get_value_from_attributes(attributes, "path");
    sfTexture **textures;
    sfIntRect rect = get_rect_dom(attributes);
    sfVector2u full_size = get_texture_size_from_path(path);
    int nb_frames;
    int i = 0;

    nb_frames = full_size.x / rect.width;
    textures = malloc(sizeof(sfTexture*) * (nb_frames + 1));
    if (!textures)
        return NULL;
    while (i < nb_frames) {
        textures[i] = sfTexture_createFromFile(path, &rect);
        rect.left += rect.width;
        i++;
    }
    textures[i] = NULL;

    return textures;
}
