/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Created by Croquette,
*/

#include "step_machine.h"
#include "xml.h"
#include "resources.h"

core_t *init_core_program(core_t *core, m_event_t *event)
{
    sfVideoMode mode = {3200, 1800, 32};
    xml_node_t *rsc_dom = get_dom_from_file("rsc/resource.xml");

    if (!resource_manager_init("rsc/resource.xml")) {
        *event = EventResourceManagerInitFailed;
        return core;
    } if (!(core->win = sfRenderWindow_create(mode, "epic rpg", sfFullscreen,
            NULL))) {
        *event = EventWindowCreateFailed;
        return core;
    } if (!(core->pools = init_pools())) {
        *event = EventPoolInitFailed;
        return core;
    }
    return core;
}