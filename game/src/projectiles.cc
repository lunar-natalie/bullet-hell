/// @file projectiles.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Entity projectile firing routines.
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

#include "game.h"

#include <cmath>

#include "bullet.h"
#include "math.h"
#include "plasma.h"

using namespace bullet_hell;

void Game::updateShipFire()
{
    // Decrement reload timer by the time since the function was last called.
    ship->reloadTimer -= elapsedTime;

    // Fire if input flag is set and the reload timer has passed the reload
    // interval.
    if (ship->isFiring && ship->reloadTimer < 0.0f) {
        // Time specified by the interval must be elapsed before the ship next
        // fires.
        ship->reloadTimer = ship->reloadInterval;

        // Create a new plasma at the ship's current position adjusted by a
        // global offset, using the global plasma speed as a base for its
        // velocity in the y-axis.
        plasmas.push_back(new Plasma(
            ship->position.x, ship->position.y + Plasma::initialYOffset, 0.0f,
            -Plasma::baseSpeed, {0.1333f, 0.1333f}));
    }
}

void Game::addBullets(unsigned int count, olc::vf2d initialPosition)
{
    // Random angle to add to each new bullet's rotational velocity.
    float offset = static_cast<float>(math::TWO_PI) * math::randomMultiplier();

    for (auto i = 0; i < count; ++i) {
        // Calculate angle required for even spread, added with the offset.
        float theta = (static_cast<float>(math::TWO_PI)
                       * (static_cast<float>(i) / static_cast<float>(count)))
                      + offset;

        // Create a new bullet at the specified start position, with velocities
        // multiplied by a speed constant and separated in the x- and
        // by pi/2 radians (distance between cos and sin) as pixels per second.
        bullets.push_back(new Bullet(
            initialPosition.x, initialPosition.y, 100.0f * std::cos(theta),
            100.0f * std::sin(theta), {0.0333f, 0.0333f}));
    }
}
