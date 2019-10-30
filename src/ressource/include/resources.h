/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** xml header
*/

#ifndef MUL_MY_RPG_2018_OBJECT_H
#define MUL_MY_RPG_2018_OBJECT_H

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "xml.h"
#include "resources_typedef.h"

typedef enum e_template{tp_null,
                        tp_root,
                        tp_scene,
                        tp_object_pool,
                        tp_texture,
                        tp_texture_anim,
                        tp_sound,
                        tp_music,
                        tp_button,
                        tp_panel,
                        tp_error} template_t;

typedef enum pools{RootTexture,
                    RootSound, RootHud, RootWeapon, RootMinion,
                    RootBuilding, RootButton, RootScene} t_root_pool;

typedef enum e_obj_id{obj_null,
                        obj_button,
                        obj_panel,
                        obj_error} t_obj_id;

struct s_resource{
    template_t type;
    void *data;
    char *name;
    struct s_resource *child;
};

typedef void *(*resource_constructor)(xml_node_t *node);
typedef void (*resource_destructor)(void *data);

struct s_resource_key{
    template_t type;
    char *key;
    resource_constructor constructor;
    resource_destructor destructor;
};

void *construct_tp_object_pool(xml_node_t *elem);
void *construct_tp_texture(xml_node_t *elem);
void *construct_tp_texture_anim(xml_node_t *elem);
void *construct_tp_sound(xml_node_t *elem);
void *construct_tp_music(xml_node_t *elem);
void *construct_tp_button(xml_node_t *elem);
void *construct_tp_root(xml_node_t *elem);
void *construct_tp_panel(xml_node_t *elem);
void *construct_tp_scene(xml_node_t *elem);

void destroy_tp_scene(void *scene);

resource_t *construct_element_from_node(xml_node_t *elem);
resource_t *get_elem_by_name(resource_t *rsc, char *name);
void *search_for_resource(char *key, char *category, char *name);

static resource_t root_pool[] = {
        {tp_root, NULL, "Texture", NULL},
        {tp_root, NULL, "Sound", NULL},
        {tp_root, NULL, "Hud", NULL},
        {tp_root, NULL, "GameConfig", NULL},
        {tp_root, NULL, "Scene", NULL},
        {tp_null, NULL, NULL, NULL}
};

static resource_key_t xml_template[] = {
        {tp_root, "Root", construct_tp_root, NULL},
        {tp_scene, "Scene", construct_tp_scene, destroy_tp_scene},
        {tp_object_pool, "ObjectPool", construct_tp_object_pool, NULL},
        {tp_texture, "Texture", construct_tp_texture, NULL},
        {tp_texture_anim, "TextureAnim", construct_tp_texture_anim, NULL},
        {tp_sound, "Sound", construct_tp_sound, NULL},
        {tp_music, "Music", construct_tp_music, NULL},
        {tp_button, "Button", construct_tp_button, NULL},
        {tp_panel, "Panel", construct_tp_panel, NULL},
        {tp_error, NULL, NULL, NULL},
        {tp_null, NULL, NULL, NULL}
};
root_t *resource_trick(root_t *new_pools, int flag);
root_t *get_resource_root(void);
int resource_manager_init(char *path);
#endif
