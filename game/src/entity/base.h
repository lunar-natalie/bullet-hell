/*
 * base.h
 *
 * Base object for an entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BULLET_HELL_ENTITY_BASE_H
#define BULLET_HELL_ENTITY_BASE_H

#include <olcPixelGameEngine.h>

namespace bullet_hell {

struct Entity {
    olc::vf2d position;
    olc::vf2d velocity;

    Entity(float x, float y, float dx, float dy);
};

}; // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_BASE_H
