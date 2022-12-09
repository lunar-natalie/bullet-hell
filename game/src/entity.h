/*
 * entity.h
 *
 * Base position-only entity object.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_ENTITY_H
#define BULLET_HELL_ENTITY_H

#include <olcPixelGameEngine.h>

namespace bullet_hell {

struct Entity {
    olc::vf2d position;

    Entity();
    Entity(float x, float y);
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_H
