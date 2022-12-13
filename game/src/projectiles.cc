//
// projectiles.cc
//
// Entity projectile firing routines.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

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
        plasmas.push_back(new Plasma(ship->position.x,
                                     ship->position.y + Plasma::initialYOffset,
                                     0.0f, -Plasma::baseSpeed));
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
        bullets.push_back(new Bullet(initialPosition.x, initialPosition.y,
                                     100.0f * cos(theta), 100.0f * sin(theta)));
    }
}
