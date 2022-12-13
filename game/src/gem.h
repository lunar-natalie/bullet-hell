/// @file gem.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Gem entity.
///
/// @section LICENSE
///
/// Copyright (c) 2022 The SFC Project Authors.
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <https://www.gnu.org/licenses/>.

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
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    /// @param type Visual type.
    /// @param scale x- and y-factors to multiply the entity's sprite size by
    /// when drawing or performing hitbox calculations.
    Gem(float x, float y, float dx, float dy, Type type,
        olc::vf2d scale = {1.0f, 1.0f});

    /// @brief Generates a random value from `Type`.
    /// @return Visual type.
    static Type randomType();
};

} // namespace bullet_hell

#endif // BULLET_HELL_GEM_H
