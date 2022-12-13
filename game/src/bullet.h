//
// bullet.h
//
// Bullet entity.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_BULLET_H
#define BULLET_HELL_BULLET_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Bullet projectile entity fired by shooters.
struct Bullet : MovingEntity {
    static Sprite* sprite;

    /// @brief Creates a new Bullet object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    Bullet(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_BULLET_H
