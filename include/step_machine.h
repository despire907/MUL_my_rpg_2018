/*
** EPITECH PROJECT, 2018
** MUL_my_rpg
** File description:
** step_machine.h
*/

#ifndef MY_RPG_STEP_MACHINE_H
#define MY_RPG_STEP_MACHINE_H
#include <SFML/Graphics.h>
#include "../src/pool/pool.h"
#include "../src/ressource/include/resources.h"

typedef enum e_machine_state{StateInit, StateRun, StateDestroy, StateError, StateEnd} state_t;

typedef enum e_machine_event{EventClear, EventWindowCreateFailed,
                        EventXmlFailed, EventLoadingRscFromDomFailed,
                        EventPoolInitFailed, EventMainSceneNotFound,
                        EventResourceManagerInitFailed,
                        EventUnknownError} m_event_t;

typedef struct s_core{
    int ac;
    char **av;
    sfRenderWindow *win;
    resource_t *rsc;
    pool_t *pools;
} core_t;

typedef state_t (*state_handler)(state_t state, m_event_t *event, core_t *core);

state_t machine_step_init(state_t state, m_event_t *event, core_t *core);
state_t machine_step_run(state_t state, m_event_t *event, core_t *core);
state_t machine_step_destroy(state_t state, m_event_t *event, core_t *core);
state_t machine_step_error(state_t state, m_event_t *event, core_t *core);
int step_machine(int ac, char **av);
core_t *init_core_program(core_t *core, m_event_t *event);
#endif //MY_RPG_STEP_MACHINE_H
