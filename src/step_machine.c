/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include <stdio.h>
#include "step_machine.h"
#include "workbench/workbench.h"
#include "pool/pool.h"
#include "resources_typedef.h"
#include "tp_scene.h"

static state_handler machine_steps[] = {&machine_step_init,
                                        &machine_step_run,
                                        &machine_step_destroy,
                                        &machine_step_error,
                                        NULL};

state_t machine_step_init(state_t state, m_event_t *event, core_t *core)
{
    init_core_program(core, event);
    state = StateRun;
    return state;
}

state_t machine_step_run(state_t state, m_event_t *event, core_t *core)
{
    static workbench_t *wb = NULL;
    static pool_t *pools = NULL;
    static tp_scene_t *scene  = NULL;

    if (!scene) {
        if (!(scene = search_for_resource("Scene", "scenes", "main_menu"))) {
            *event = EventMainSceneNotFound;
            return StateError;
        }
    }
    if (!wb)
        wb = new_workbench(scene);

    state = StateDestroy;
    return state;
}

state_t machine_step_destroy(state_t state, m_event_t *event, core_t *core)
{
    state = StateEnd;
    *event = EventClear;
    return state;
}

state_t machine_step_error(state_t state, m_event_t *event, core_t *core)
{
    state = StateDestroy;
    return state;
}

int step_machine(int ac, char **av)
{
    state_t state = StateInit;
    m_event_t event = EventClear;
    state_handler handler = machine_steps[state];
    core_t core = {ac, av};

    while (state != StateEnd) {
        state = handler(state, &event, &core);
        handler = machine_steps[state];
    }
    if (event == EventClear)
        return 0;
    return 84;
}
