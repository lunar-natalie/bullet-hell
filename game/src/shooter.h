//
// shooter.h
//
// Shooter entity.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_SHOOTER_H
#define BULLET_HELL_SHOOTER_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Enemy shooter entity.
struct Shooter : MovingEntity {
    static Sprite* sprite;

    /// @brief Global timer for spawning new shooters. Set to `spawnInterval`
    /// and decrease by elapsed time until 0.0f seconds before spawning.
    /// Initially unset.
    static float spawnTimer;

    /// @brief Time in seconds before new shooters should be spawned.
    static float spawnInterval;

    /// @brief Default initial y-position in pixels for new shooters.
    static float startY;

    /// @brief Default initial x-velocity in pixels per second for new shooters.
    static float defaultXVelocity;

    /// @brief Default initial y-velocity in pixels per second for new shooters.
    static float defaultYVelocity;

    static float defaultFireRate;
    static unsigned int defaultFireCount;

    /// @brief Number of times to fire per second.
    float fireRate;

    /// @brief Number of bullets to fire at each interval determined by the fire
    /// rate.
    unsigned int fireCount;

    /// @brief Remaining seconds until the shooter should next fire.
    float fireTimer;

    /// @brief Creates a new Shooter object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    /// @param fireRate Number of times to fire per second.
    /// @param fireCount Number of bullets to fire at each interval determined
    /// by the fire rate.
    Shooter(float x, float y = startY, float dx = defaultXVelocity,
            float dy = defaultYVelocity, float fireRate = defaultFireRate,
            unsigned int fireCount = defaultFireCount);
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHOOTER_H
