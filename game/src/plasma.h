/*
 * plasma.h
 *
 * Plasma entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_PLASMA_H
#define BULLET_HELL_PLASMA_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Plasma projectile entity fired by the ship.
struct Plasma : MovingEntity {
    static Sprite* sprite;

    /// @brief Offset from the y-position of the firing ship in pixels. Used to
    /// set the position of newly spawned plasmas.
    static float initialYOffset;

    /// @brief Positive speed used to set the Plasma's velocity.
    static float baseSpeed;

    /// @brief Creates a new Plasma object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    Plasma(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_PLASMA_H
