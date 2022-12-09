/*
 * moving_entity.h
 *
 * Entity object with velocity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_MOVING_ENTITY_H
#define BULLET_HELL_MOVING_ENTITY_H

#include <olcPixelGameEngine.h>

#include "entity.h"

namespace bullet_hell {

struct MovingEntity : public Entity {
    olc::vf2d velocity;

    MovingEntity();
    MovingEntity(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_MOVING_ENTITY_H
