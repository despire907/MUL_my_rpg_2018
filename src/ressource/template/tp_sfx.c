/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "include/tp_sfx.h"

sfSound *get_sound_dom(kv_t *attributes)
{
    char *path = get_attributes_dom(attributes, "path");
    sfSoundBuffer *sound_buffer;
    sfSound *sound = NULL;

    if (!path)
        return NULL;
    sound_buffer = sfSoundBuffer_createFromFile(path);
    if (!sound_buffer)
        return NULL;
    sfSound_setBuffer(sound, sound_buffer);

    return sound;
}

void *construct_tp_sound(xml_node_t *elem)
{
    tp_sound_t *new_elem = malloc(sizeof(tp_sound_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    new_elem->sound = get_sound_dom(elem->attributes);

    return new_elem;
}

sfMusic *get_music_dom(kv_t *attributes)
{
    char *path = get_attributes_dom(attributes, "path");
    sfMusic *music;

    if (!path)
        return NULL;
    music = sfMusic_createFromFile(path);

    return music;
}

void *construct_tp_music(xml_node_t *elem)
{
    tp_music_t *new_elem = malloc(sizeof(tp_music_t));

    if (!new_elem)
        return NULL;
    new_elem->name = get_attributes_dom(elem->attributes, "name");
    if ((new_elem->music = get_music_dom(elem->attributes)))
        new_elem->duration = sfMusic_getDuration(new_elem->music);
    else
        new_elem->duration = sfTime_Zero;

    return new_elem;
}