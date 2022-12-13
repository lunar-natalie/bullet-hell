//
// moving_entity.h
//
// Entity object with velocity.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_MOVING_ENTITY_H
#define BULLET_HELL_MOVING_ENTITY_H

#include <olcPixelGameEngine.h>

#include "entity.h"

namespace bullet_hell {

/// @brief Representation of a moving visible object in the game.
struct MovingEntity : Entity {
    /// @brief Velocity of the object in pixels per second.
    olc::vf2d velocity;

    /// @brief Creates a new empty MovingEntity object.
    MovingEntity();

    /// @brief Creates a new MovingEntity object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    MovingEntity(float x, float y, float dx, float dy);

    /// @brief Increments the entity's position by the provided time multiplied
    /// by the entity's velocity.
    /// @param elapsedTime Time elapsed in seconds since the function was last
    /// called.
    void updatePosition(float elapsedTime);
};

} // namespace bullet_hell

#endif // BULLET_HELL_MOVING_ENTITY_H
