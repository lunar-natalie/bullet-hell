/*
 * explosion.h
 *
 * Explosion entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_EXPLOSION_H
#define BULLET_HELL_EXPLOSION_H

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "partial_sprite.h"

namespace bullet_hell {

/// @brief Animated explosion entity.
struct Explosion : Entity {
    static PartialSprite* sprite;

    /// @brief Number of frames to show per second.
    static float frameRate;

    /// @brief Time elapsed in seconds since the last frame was drawn.
    float frameTimer;

    /// @brief Creates a new Explosion object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    Explosion(float x, float y);

    /// @brief Updates `frameTimer` and checks whether the next frame should be
    /// drawn.
    /// @param elapsedTime Time elapsed in seconds since the function was last
    /// called.
    /// @return `true` if the next frame should be drawn, otherwise `false`.
    bool update(float elapsedTime);
};

} // namespace bullet_hell

#endif // BULLET_HELL_EXPLOSION_H
