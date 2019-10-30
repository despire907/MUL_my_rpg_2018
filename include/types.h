/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** types.h
*/

#ifndef MUL_MY_RPG_2018_TYPES_H
#define MUL_MY_RPG_2018_TYPES_H

typedef enum e_g_o_type g_o_type_t;

typedef struct s_game_object g_o_t;
typedef struct s_game_event g_event_t;

typedef struct s_particule part_t;
typedef struct s_particule_field part_field_t;

typedef struct s_object_handlers object_handlers_t;
typedef void *(*object_constructor)(void);
typedef void *(*object_setter)(void *source, void *value);
typedef void (*object_destructor)(void *obj);
typedef void *(*object_handler)(void *obj);
#endif //MUL_MY_RPG_2018_TYPES_H
