/*
 * gem.h
 *
 * Gem entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_GEM_H
#define BULLET_HELL_GEM_H

#include "moving_entity.h"
#include "partial_sprite.h"

namespace bullet_hell {

/// @brief Collectible gem entity.
struct Gem : MovingEntity {
    static PartialSprite* sprite;

    /// @brief Visual type, represented as horizontally sequenced frames in the
    /// source sprite.
    enum class Type : unsigned int {
        RED = 0,
        YELLOW = 1,
        GREEN = 2,
        BLUE = 3
    } type;

    /// @brief Number of visual types in the `Type` enum.
    static constexpr const unsigned int typeCount = 4;

    /// @brief Global timer for spawning new gems. Set to `spawnInterval` and
    /// decrease by elapsed time until 0.0f seconds before spawning. Initially
    /// unset.
    static float spawnTimer;

    /// @brief Time in seconds before new gems should be spawned.
    static float spawnInterval;

    /// @brief Default initial y-position in pixels for new gems.
    static float startY;

    /// @brief Default initial x-velocity in pixels per second for new gems.
    static float defaultXVelocity;

    /// @brief Default initial y-velocity in pixels per second for new gems.
    static float defaultYVelocity;

    /// @brief Creates a new Gem object.
    /// @param type Visual type.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    Gem(Type type, float x, float y = startY, float dx = defaultXVelocity,
        float dy = defaultYVelocity);

    /// @brief Generates a random value from `Type`.
    /// @return Visual type.
    static Type randomType();
};

} // namespace bullet_hell

#endif // BULLET_HELL_GEM_H
