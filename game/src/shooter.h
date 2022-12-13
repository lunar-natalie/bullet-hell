/// @file shooter.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Shooter entity implementation.
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

#ifndef BULLET_HELL_SHOOTER_H
#define BULLET_HELL_SHOOTER_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Enemy entity.
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
    /// @param scale x- and y-factors to multiply the entity's sprite size by
    /// when drawing or performing hitbox calculations.
    Shooter(float x, float y, float dx, float dy, float fireRate,
            unsigned int fireCount, olc::vf2d scale = {1.0f, 1.0f});
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHOOTER_H
